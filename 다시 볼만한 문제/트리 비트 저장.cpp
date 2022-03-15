//프로그래머스 양과 늑대

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v[20];
int answer = 1;
bool chk[1<<17][17];
void dfs(vector<int> &info,int now, int stat, int scnt, int wcnt){
    answer = max(answer,scnt);
    if(scnt <= wcnt) return;
    for(int i=0;i<v[now].size();i++){
        int next = v[now][i];
        if((stat & (1<<next))){ //갔던 곳
            if(chk[stat][next]) continue;
            chk[stat][next] = true;
            dfs(info,next,stat,scnt,wcnt);            
        }
        else{
            int nextstat = (stat | (1<<next));
            chk[nextstat][next] = true;
            if(info[next]) dfs(info,next,nextstat,scnt,wcnt+1);
            else dfs(info,next,nextstat,scnt+1,wcnt);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for(int i=0;i<edges.size();i++){
        v[edges[i][0]].push_back(edges[i][1]);
        v[edges[i][1]].push_back(edges[i][0]);
    }
    dfs(info,0,1,1,0);
    return answer;
}