#include <string>
#include <vector>

using namespace std;

int chk[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++){
        int now = results[i][0];
        int next = results[i][1];
        chk[now][next] = 1;
        chk[next][now] = -1;
    }
    for(int i=1;i<=n;i++){
        chk[i][i] = true;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(chk[i][j]==1 || chk[i][j]==-1)
                    continue;
                if(chk[i][k]==1 && chk[k][j]==1)
                    chk[i][j] = 1;
                if(chk[i][k]==-1 && chk[k][j]==-1)
                    chk[i][j] = -1;                
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d",chk[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=n;i++){
        bool flag = true;
        for(int j=1;j<=n;j++){
            if(i==j) continue;
            if(!chk[i][j]){
                flag = false;
                break;
            }                
        }
        if(flag) answer++;
    }
    return answer;
}