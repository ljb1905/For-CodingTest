#include <stdio.h>
#include <algorithm>
using namespace std;

char arr[51][51];
int dp[51][51];
int chk[51][51];
int n, m;
bool flag = false;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int dfs(int y, int x) {
	if (y <= 0 || y > n || x <= 0 || x > m) return 0;
	if (flag) return 0;
	if (arr[y][x] == 'H') return 0;
	if (chk[y][x]) {
		flag = true;
		return -1;
	}
	if (dp[y][x]!=0) return dp[y][x];
	chk[y][x] = true;
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int nexty = y + (arr[y][x] - '0')*dy[i];
		int nextx = x + (arr[y][x] - '0')*dx[i];
		dp[y][x] = max(dp[y][x], dfs(nexty, nextx) + 1);
	}
	chk[y][x] = false;

	return dp[y][x];
}

int main() {
	scanf("%d %d", &n, &m);
	int ans = 0;
	char tmp;
	for (int i = 1; i <= n; i++) {
		scanf("%c", &tmp);
		for (int j = 1; j <= m; j++) {
			scanf("%c", &arr[i][j]);
		}
	}
	ans = dfs(1, 1);
	if (flag) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}