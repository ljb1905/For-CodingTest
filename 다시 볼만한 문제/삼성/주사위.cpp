//백준 14499

#include <stdio.h>

int n, m;
int arr[21][21];
int dice[6]; // 1이 위쪽  3이 아래

void swdice(int dir) {
	if (dir == 1) {
		int tmp = dice[4];
		dice[4] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[1];
		dice[1] = tmp;
	}
	else if (dir == 2) {
		int tmp = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[3];
		dice[3] = tmp;
	}
	else if (dir == 3) {
		int tmp = dice[0];
		dice[0] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = tmp;
	}
	else {
		int tmp = dice[0];
		dice[0] = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = tmp;
	}
	return;
}

int main() {
	int stx, sty, k; scanf("%d %d %d %d %d", &n, &m, &sty, &stx, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < k; i++) {
		int x; scanf("%d", &x);
		int dy, dx;
		if (x == 1) {
			dy = 0;
			dx = 1;
		}
		else if (x == 2) {
			dy = 0;
			dx = -1;
		}
		else if (x == 3) {
			dy = -1;
			dx = 0;
		}
		else {
			dy = 1;
			dx = 0;
		}
		int nexty = sty + dy;
		int nextx = stx + dx;
		if (nexty >= n || nexty < 0 || nextx >= m || nextx < 0) continue;
		swdice(x);
		if (arr[nexty][nextx] == 0) {
			arr[nexty][nextx] = dice[3];
		}
		else {
			dice[3] = arr[nexty][nextx];
			arr[nexty][nextx] = 0;
		}
		sty = nexty;
		stx = nextx;
		printf("%d\n", dice[1]);
	}
	return 0;
}