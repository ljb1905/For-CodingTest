#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer = 0;
bool chk[10];
vector<int> anslist;

void dfs(int n, int col, int row, vector<vector<string>> &relation){
    int comp = 0;
    for(int x=0;x<col;x++){
        if(chk[x]) comp+=(1<<x);
    }
    for(int i=0;i<anslist.size();i++){
        if((anslist[i] & comp )== anslist[i]) return;
    }
    if(n==col){
        bool sw = false;
        for(int i=0;i<row;i++){
            for(int j=i+1;j<row;j++){
                string now = "";
                string next = "";
                for(int k=0;k<col;k++){
                    if(!chk[k]) continue;
                    now += relation[i][k];
                    next += relation[j][k];
                }
                if(now==next){
                    sw = true;
                    break;
                }
            }
            if(sw) break;
        }
        if(!sw){
            answer++;
            int inp = 0;
            for(int x=0;x<col;x++){
                if(chk[x]) inp += (1<<(x));
            }
            anslist.push_back(inp);
        } 
        return;
    }
    dfs(n+1,col,row,relation);
    for(int i=0;i<anslist.size();i++){
        if((anslist[i] & comp )== anslist[i]) return;
    }
    chk[n] = true;
    dfs(n+1,col,row,relation);
    chk[n] = false;
}

int solution(vector<vector<string>> relation) {
    dfs(0,relation[0].size(),relation.size(),relation);
    return answer;
}