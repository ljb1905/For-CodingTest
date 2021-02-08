#include <stdio.h>

int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
int arr[51][51] = { 0, };
int n, m, k;

void func(int y, int x) {
	arr[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int nexty = y + dy[i];
		int nextx = x + dx[i];
		if (nexty >= n || nextx >= m || nexty < 0 || nextx < 0) {
			continue;
		}
		if (arr[nexty][nextx] == 0)
			continue;
		func(nexty, nextx);
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			int a, b; scanf("%d %d", &a, &b);
			arr[a][b] = 1;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1) {
					func(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}