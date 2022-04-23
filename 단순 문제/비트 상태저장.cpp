#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[17][17];
bool chk[17][17][2<<17]; //cnt, now, state
int ans = 1;
int n;

void dfs(int cnt, int now, int buy, int stat) {
	ans = max(ans, cnt);
	if (cnt == n || chk[cnt][now][stat]) return;
	chk[cnt][now][stat] = true;
	for (int i = 1; i <= n; i++) {
		if (buy <= arr[now][i] && !chk[cnt+1][i][stat | 1 << (i-1)] && i != now && !(stat & 1<<(i-1))) {
			//
			printf("%d이%d한테 팔고 개수 %d\n", now, i, cnt + 1);
			//
			dfs(cnt + 1, i, arr[now][i], (stat | 1 << (i - 1)));
		}
	}
	//chk[now] = true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	dfs(1, 1, 0, 1);
	printf("%d\n", ans);
	return 0;
}