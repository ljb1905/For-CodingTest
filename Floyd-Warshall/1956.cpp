#include <stdio.h>
#include <algorithm>
using namespace std;

int dis[401][401];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = 987654321;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		dis[a][b] = c;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	int ans = 987654321;
	for (int i = 1; i <= n; i++)
		ans = min(ans, dis[i][i]);
	if (ans == 987654321)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}