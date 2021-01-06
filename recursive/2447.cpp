#include <stdio.h>

char arr[7000][7000];

void dfs(int val, int y, int x) {
	if (val == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == 1 && j == 1)
					continue;
				arr[y + i][x + j] = '*';
			}
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1)
				continue;
			int tmp = val / 3;
			dfs(tmp, y + tmp * i, x + tmp * j);
		}
	}
}

int main()
{
	int n; scanf("%d", &n);
	dfs(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				printf(" ");
				continue;
			}
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}