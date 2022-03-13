#include <stdio.h>

int arr[10];
int ans[10];
int n, m;
bool chk[10];

void dfs(int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		if (chk[i]) continue;
		chk[i] = true;
		ans[idx] = arr[i];
		dfs(idx + 1);
		chk[i] = false;
	}
	return; 
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0);
	return 0;
}