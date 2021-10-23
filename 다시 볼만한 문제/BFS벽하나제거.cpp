#include <stdio.h>
#include <queue>
using namespace std;

struct strr {
	int y, x, cost;
	bool chk;
	strr() {}
	strr(int y, int x, int cost, bool chk)
		:y(y), x(x), cost(cost), chk(chk)
	{}
};

int arr[1011][1011];
bool visit[1011][1011][2];
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };
queue <strr> q;

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i <= n + 1; i++) {
		visit[i][m + 1][0] = true;
		visit[i][0][0] = true;
		visit[i][m + 1][1] = true;
		visit[i][0][1] = true;
	}
	for (int j = 0; j <= m + 1; j++) {
		visit[0][j][0] = true;
		visit[n + 1][j][0] = true;
		visit[0][j][1] = true;
		visit[n + 1][j][1] = true;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	strr st(1, 1, 1, false);
	q.push(st);
	int ans = 0;
	while (!q.empty()) {
		strr now = q.front();
		q.pop();
		int nowy = now.y;
		int nowx = now.x;
		bool block = now.chk;
		if (nowy == n && nowx == m) {
			ans = now.cost;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nexty = nowy + dy[i];
			int nextx = nowx + dx[i];
			if (arr[nexty][nextx] == 1 && block == false) {
				strr x(nexty,nextx,now.cost+1,true);
				visit[nexty][nextx][block] = true;
				q.push(x);
			}
			else if (arr[nexty][nextx] == 0 && visit[nexty][nextx][block] == false) {
				strr x(nexty, nextx, now.cost + 1, block);
				q.push(x);
				visit[nexty][nextx][block] = true;
			}
			
		}
	}
	if (ans == 0)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}