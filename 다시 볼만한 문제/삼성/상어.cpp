#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int arr[22][22];
bool chk[22][22];
int dis[22][22];
int n;
int f_cnt;
int e_cnt;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct s {
    int y, x, cost;
    s() {}
    s(int y, int x, int cost) :y(y), x(x), cost(cost) {}
};
void set_dis() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = 987654321;
        }
    }
    return;
}
void find_dis(int y, int x, int cost, int sz) {
    queue <s> q;
    q.push(s(y, x, cost));
    while (!q.empty()) {
        int nowy = q.front().y;
        int nowx = q.front().x;
        int nowcost = q.front().cost;
        q.pop();
        dis[nowy][nowx] = nowcost;
        for (int k = 0; k < 4; k++) {
            int nexty = nowy + dy[k];
            int nextx = nowx + dx[k];
            if (dis[nexty][nextx] != 987654321) continue;
            if (nexty <= 0 || nexty >= n + 1 || nextx <= 0 || nextx >= n + 1) continue;
            if (sz < arr[nexty][nextx]) continue;
            q.push(s(nexty, nextx, nowcost + 1));
            dis[nexty][nextx] = nowcost + 1;
        }
    }
    return;
}

int main() {
    scanf("%d", &n);
    int sty, stx;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 9) {
                sty = i;
                stx = j;
                arr[i][j] = 0;
            }
            if (arr[i][j] != 0) {
                chk[i][j] = true;
                f_cnt++;
            }
        }
    }
    int nowi = sty;
    int nowj = stx;
    int sz = 2;
    int ans = 0;
    int temp_cnt = 0;
    while (e_cnt < f_cnt) {
        set_dis();
        find_dis(nowi, nowj, 0, sz);
        int minn = 987654321;
        int nexti = 0;
        int nextj = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (chk[i][j] && minn > dis[i][j] && sz > arr[i][j]) {
                    minn = dis[i][j];
                    nexti = i;
                    nextj = j;
                }
            }
        }
        //
         /*for(int i=1;i<=n;i++){
             for(int j=1;j<=n;j++){
                 printf("%d ",dis[i][j]);
             }
             printf("\n");
         }*/
        //printf("%d %d %d %d %d\n",nowi,nowj,minn,ans,sz);
        //
        if (nexti == 0) {
            break;
        }
        nowi = nexti;
        nowj = nextj;
        ans += dis[nowi][nowj];
        chk[nowi][nowj] = false;
        e_cnt++;
        temp_cnt++;
        if (temp_cnt >= sz) {
            sz++;
            temp_cnt = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}