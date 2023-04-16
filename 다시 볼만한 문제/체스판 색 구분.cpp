#include <stdio.h>
#include <algorithm>
using namespace std;

int n; 
int arr[11][11];
bool chk1[21];
bool chk2[21];
int ans = 0;
int ans2 = 0;

void dfs(int now, int cnt, bool flag){
    if(now>n*n) return;
    for(int i=now; i<=n*n; i++){ 
        int nexty = i/n + 1;
        int nextx = i%n;
        if(nextx == 0){
            nexty--;
            nextx+=n;
        }
        if(nexty>n || nextx>n || nexty<=0 || nextx<=0) continue;
        if((nextx+nexty)%2==1 && flag==false) continue;
        if((nextx+nexty)%2==0 && flag==true) continue;  
        if(chk1[nexty+nextx]) continue;
        if(chk2[n+nextx-nexty]) continue;
        if(arr[nexty][nextx] == 0) continue;
        //printf("%d %d\n",nexty,nextx);
        chk1[nexty+nextx] = true;
        chk2[n+nextx-nexty] = true;
        dfs(i + 1 , cnt + 1, flag);
        if(flag) ans = max(ans, cnt+1);
        else ans2 = max(ans2, cnt+1);
        chk1[nexty+nextx] = false;
        chk2[n+nextx-nexty] = false;
    }
}

int main (){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    //if(n==1 && arr[1][1] == 1) ans=1;
    dfs(1,0,false);
    dfs(2,0,true);
    printf("%d\n",ans+ans2);

    return 0;
}