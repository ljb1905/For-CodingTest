#include<iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[22][22] = {0,};
bool chk[22][22] = {0,};
int dx[4] = {-1,-1,1,1};
int dy[4] = {-1,1,-1,1};
bool stat_arr[4] = {0,};

int dfs(int sty,int stx,int i,int j,int cnt, int stat){//stat은 어느방향으로 갈것이냐
    if(i==sty && j==stx && cnt!=0) return cnt;
    if(chk[i][j]) return 0;
    chk[i][j] = true;
    //
    //printf("%d %d\n",i,j);
    //
    int ret = 0;
    for(int mul=1;mul<=10;mul++){
        for(int k=0;k<4;k++){
            int nexti = i + mul*dy[k];
            int nextj = j + mul*dx[k];
            if(nexti>=21 || nexti <= 0 || nextj >=21 || nextj <= 0) continue;
            if(chk[nexti][nextj]) continue;
            if(stat_arr[k]) continue;
            // if(stat==0 && k==3) continue;
            // else if(stat==1 && k==2) continue;
            // else if(stat==2 && k==1) continue;
            // else if(stat==3 && k==0) continue;
            stat_arr[k] = true;
            ret = max(ret,dfs(sty,stx,nexti,nextj,cnt+1,k));
            stat_arr[k] = false;
        }
    }    
    return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{     
        int ans = -1;
		int n; scanf("%d",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&arr[i][j]);
            }
            for(int i=0;i<=n+1;i++){
                chk[i][0] = true;
                chk[i][n+1] = true;
            }
            for(int j=0;j<=n+1;j++){
                chk[0][j] = true;
                chk[n+1][j] = true;
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    for(int y=1;y<=n;y++){
                        for(int x=1;x<=n;x++){
                            chk[y][x] = false;
                        }
                    }
                    for(int x=0;x<4;x++){
                        ans = max(ans,dfs(i,j,i,j,0,x));
                    }
                }
            }
        }
        printf("%d\n",ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}