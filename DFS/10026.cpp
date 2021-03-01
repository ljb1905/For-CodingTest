#include <stdio.h>

char arr[101][101];
bool visit[2][101][101];
int ans[2];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
int n;

void dfs(bool chk, int i, int j, char x) {
	visit[chk][i][j]=true;
	for (int a = 0; a < 4; a++) {
		int nexti = i + dy[a];
		int nextj = j + dx[a];
		if (nexti < 0 || nexti >= n || nextj < 0 || nextj >= n) 
			continue;
		if (visit[chk][nexti][nextj] == true)
			continue;
		if (chk == 0 && arr[nexti][nextj] == x) {
			dfs(chk, nexti, nextj, x);
		}
		else if (chk == 1 && (x=='R' || x=='G')&&(arr[nexti][nextj] == 'R' || arr[nexti][nextj] == 'G')) {
			dfs(chk, nexti, nextj, x);
		}
		else if (chk == 1 && (x == arr[nexti][nextj])) {
			dfs(chk,nexti,nextj,x);
		}
	}
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[0][i][j] == false) {
				char x = arr[i][j];
				dfs(0, i, j, x);
				ans[0]++;
			}
			if (visit[1][i][j] == false) {
				char x = arr[i][j];
				dfs(1, i, j, x);
				ans[1]++;
			}
		}
	}
	printf("%d %d\n", ans[0], ans[1]);

	return 0;
}