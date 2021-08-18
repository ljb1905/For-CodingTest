#include <stdio.h>
#include <queue>
using namespace std;

int inp[111][111];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
struct s {
	int y, x;
	s() {}
	s(int y, int x) :
		y(y), x(x)
	{}
};

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &inp[i][j]);
			if (inp[i][j] == 1) cnt++;
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		inp[i][0] = 987654321;
		inp[i][m + 1] = 987654321;
	}
	for (int i = 0; i <= m + 1; i++) {
		inp[0][i] = 987654321;
		inp[n + 1][i] = 987654321;
	}
	while (cnt > 0) {
		ans++;
		bool chk[101][101] = { 0, };
		queue<s> q;
		q.push(s(1, 1));
		while (!q.empty()) {
			int nowy = q.front().y;
			int nowx = q.front().x;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nexty = nowy + dy[i];
				int nextx = nowx + dx[i];
				if (inp[nexty][nextx] == 987654321) continue;
				if (chk[nexty][nextx]) continue;
				if (inp[nexty][nextx] >= 1) {
					inp[nexty][nextx]++;
					continue;
				}
				q.push(s(nexty, nextx));
				chk[nexty][nextx] = true;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (inp[i][j]>=3) {
					inp[i][j] = 0;
					cnt--;
				}
				else if (inp[i][j] == 2) {
					inp[i][j] = 1;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}