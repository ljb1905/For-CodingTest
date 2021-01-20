#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int arr[111][111];
int visit[111][111][4];
int dy[5] = { 0,0,0,1,-1 };
int dx[5] = { 0,1,-1,0,0 };

struct strr {
	int y, x, dir;
	strr() {}
	strr(int y, int x, int dir) :
		y(y), x(x), dir(dir)
	{}
};
queue <strr> q;

int costup(int nowdir, int nexdir) {
	if (nowdir == nexdir) {
		return 0;
	}
	if (nowdir == 1) {
		if (nexdir == 2) {
			return 2;
		}
		return 1;
	}
	if (nowdir == 2) {
		if (nexdir == 1) {
			return 2;
		}
		return 1;
	}
	if (nowdir == 3) {
		if (nexdir == 4) {
			return 2;
		}
		return 1;
	}
	if (nowdir == 4) {
		if (nexdir == 3) {
			return 2;
		}
		return 1;
	}
}

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	int ans = 987654321;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		arr[i][0] = 1;
		arr[i][m + 1] = 1;
	}
	for (int j = 0; j <= m + 1; j++) {
		arr[0][j] = 1;
		arr[n + 1][j] = 1;
	}
	int sty, stx, std; scanf("%d %d %d", &sty, &stx, &std);
	q.push(strr(sty, stx, std));
	int edy, edx, edd; scanf("%d %d %d", &edy, &edx, &edd);
	while (!q.empty()) {
		strr now = q.front();
		q.pop();
		int nowy = now.y;
		int nowx = now.x;
		int nowd = now.dir;
		
		//printf("%d %d %d %d\n", nowy, nowx, nowd, visit[nowy][nowx][nowd]);

		if (nowy == edy && nowx == edx) {
			ans = min(ans, visit[edy][edx][nowd]+costup(nowd,edd));
		}
		for (int i = 1; i <= 3; i++) { // *3까지 보내기
			int nexty = now.y + dy[nowd] * i;
			int nextx = now.x + dx[nowd] * i;
			if (nexty > n || nexty < 1 || nextx > m || nextx < 1)
				break;
			if (arr[nexty][nextx] == 1)
				break;
			if (visit[nexty][nextx][nowd] != 0)
				continue;
			q.push(strr(nexty, nextx, nowd));
			visit[nexty][nextx][nowd] = visit[nowy][nowx][nowd]+1;			
		}
		for (int i = 1; i <= 4; i++) { // 방향 돌리기
			int nextd = i;
			if (nextd == nowd) {
				continue;
			}
			if (visit[nowy][nowx][nextd] != 0)
				continue;
			q.push(strr(nowy, nowx, nextd));
			visit[nowy][nowx][nextd] = visit[nowy][nowx][nowd]+costup(nowd,nextd);
		}
	}	

	printf("%d\n", ans);
	return 0;
}