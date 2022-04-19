// 백준 13460

#include <stdio.h>
#include <queue>
using namespace std;

struct s {
	int ry, rx, by, bx, cnt;
	s(){}
	s(int ry,int rx, int by, int bx, int cnt):
		ry(ry),rx(rx),by(by),bx(bx),cnt(cnt)
	{}
};

char arr[11][11];
bool chk[11][11][11][11];
int hy, hx;
queue<s> q;

pair<int, int> find_next(int anoy, int anox, int nowy, int nowx, int dir) {
	int incy = 0;
	int incx = 0;
	if (dir == 0) incy = -1;
	else if (dir == 1) incy = 1;
	else if (dir == 2) incx = -1;
	else incx = 1;
	while (1) {
		int nexty = nowy + incy;
		int nextx = nowx + incx;
		if (arr[nexty][nextx] == '#' || (nexty == anoy && nextx == anox)) {
			return make_pair(nowy, nowx);
		}
		else if (arr[nexty][nextx] == 'O') {
			return make_pair(0, 0);
		}
		nowy = nexty;
		nowx = nextx;
	}
}


int main() {
	int n, m; scanf("%d %d", &n, &m);
	char inptmp;
	int rsty, rstx, bstx, bsty;
	for (int i = 0; i < n; i++) {
		scanf("%c", &inptmp);
		for (int j = 0; j < m; j++) {
			scanf("%c", &arr[i][j]);
			if (arr[i][j] == 'R') {
				rsty = i;
				rstx = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B') {
				bsty = i;
				bstx = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'O') {
				hy = i;
				hx = j;
			}
		}
	}
	q.push(s(rsty, rstx, bsty, bstx,0));
	while (!q.empty()) {
		s now = q.front();
		q.pop();
		chk[now.ry][now.rx][now.by][now.bx] = true;
		if (now.cnt >= 10) {
			printf("-1\n");
			return 0;
		}
		for (int i = 0; i < 4; i++) { //위 아래 왼 오
			int rnexty, rnextx;
			int bnexty, bnextx;
			if ((i == 0 && now.ry < now.by) ||(i==1 && now.ry>=now.by) || (i == 2 && now.rx < now.bx) || (i == 3 && now.rx >= now.bx)) {
				pair<int, int> tmp = find_next(now.by, now.bx, now.ry, now.rx, i);
				rnexty = tmp.first;
				rnextx = tmp.second;
				tmp = find_next(rnexty, rnextx, now.by, now.bx, i);
				bnexty = tmp.first;
				bnextx = tmp.second;
			}
			else if ((i == 0 && now.ry >= now.by)||(i==1 && now.ry < now.by)||(i==2 && now.rx>=now.bx)||(i==3 && now.rx<now.bx)) {
				pair<int, int> tmp = find_next(now.ry, now.rx, now.by, now.bx, i);
				bnexty = tmp.first;
				bnextx = tmp.second;
				tmp = find_next(bnexty, bnextx, now.ry, now.rx, i);
				rnexty = tmp.first;
				rnextx = tmp.second;
			}
			//
			if (bnexty == 0) {
				continue;
			}
			if (rnexty == 0) {
				printf("%d\n", now.cnt + 1);
				return 0;
			}
			if (chk[rnexty][rnextx][bnexty][bnextx]) continue;
			q.push(s(rnexty, rnextx, bnexty, bnextx, now.cnt + 1));
		}
	}
	printf("-1\n");
	return 0;
}