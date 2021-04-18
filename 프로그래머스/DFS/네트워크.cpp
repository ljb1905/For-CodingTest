#include <string>
#include <vector>

using namespace std;

bool chk[201];

void dfs(int n, vector<vector<int>> &v, int nn){
    if(chk[n]==true) return;
    chk[n] = true;
    for(int i=0;i<nn;i++){
        if(v[n][i]==1 && chk[i]==false){
            dfs(i,v,nn);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(chk[i]==false){
            dfs(i,computers,n);
            answer++;   
        }
    }
    return answer;
}