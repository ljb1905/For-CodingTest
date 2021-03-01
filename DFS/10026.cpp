#include <stdio.h>

char arr[101][101];
bool visit[2][101][101];
int ans[2];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
int n;

int dfs(bool chk, int i, int j, char x) {
	for (int a = 0; a < 4; a++) {
		int nexti = i + dy[a];
		int nextj = j + dx[a];
		if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= n) 
			continue;
		if (visit[chk][nexti][nextj] == true)
			continue;
		if (arr[nexti][nextj] == x) {

		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[0][i][j] == false) {
				char x = arr[i][j];
				dfs(0, i, j, x);
				ans[0]++;
			}
		}
	}

	return 0;
}