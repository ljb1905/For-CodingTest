#include <stdio.h>

int ori[10][10];

bool chkfun(int y, int x, int val) {
	int cnta[10] = { 0, };
	int cntb[10] = { 0, };
	int cntc[10] = { 0, };
	bool ret = true;
	for (int i = 0; i < 9; i++) {
		cnta[ori[y][i]]++;
	}
	for (int i = 0; i < 9; i++) {
		cntb[ori[i][x]]++;
	}
	int tmpy = y / 3;
	int tmpx = x / 3;
	for (int i = tmpy * 3; i < tmpy * 3 + 3; i++) {
		for (int j = tmpx * 3; j < tmpx * 3 + 3; j++) {
			cntc[ori[i][j]]++;
		}
	}
	cnta[val]++;
	cntb[val]++;
	cntc[val]++;
	for (int i = 1; i <= 9; i++) {
		if (cnta[i] > 1)
			ret = false;
		if (cntb[i] > 1)
			ret = false;
		if (cntc[i] > 1)
			ret = false;
	}
	return ret;
}

bool dfs(int y, int x) {
	if (x >= 9) {
		y++;
		x = 0;
	}
	if (y >= 9)
		return true;
	if (ori[y][x])
		return dfs(y, x + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (chkfun(y, x, i)) {
				ori[y][x] = i;
				if (dfs(y, x + 1))
					return true;
				ori[y][x] = 0;
			}
		}
	}
	return false;
}

int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &ori[i][j]);
		}
	}
	dfs(0, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", ori[i][j]);
		}
		printf("\n");
	}
	return 0;
}