#include <string>
#include <queue>
#include <vector>

using namespace std;
bool chk[20001];
struct s{
    int ver;
    int cost;
    s(){}
    s(int ver,int cost):
    ver(ver),cost(cost)
    {}
};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector <vector<int>> v;
    for(int i=0;i<n+1;i++){
        vector<int> tmp;
        v.push_back(tmp);
    }
    for(int i=0;i<edge.size();i++){
        int now = edge[i][0];
        int next = edge[i][1];
        v[now].push_back(next);
        v[next].push_back(now);
    }
    queue <s> q;
    q.push(s(1,0));
    chk[1] = true;
    int maxx = 0;
    while(!q.empty()){
        int now = q.front().ver;
        int cost = q.front().cost;
        q.pop();
        chk[now]=true;
        if(maxx < cost){
            answer = 1;
            maxx = cost;
        }
        else if(maxx == cost){
            answer++;
        }
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i];
            if(chk[next]){
                continue;
            }
            q.push(s(next,cost+1));
            chk[next]=true;
        }
    }
    return answer;
}