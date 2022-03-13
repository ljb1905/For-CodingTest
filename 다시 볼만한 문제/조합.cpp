#include <stdio.h>

int arr[10];
int ans[10];
int n, m;

void dfs(int idx, int l) {
	if (l == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
		return;
	}
	for (int i = idx; i < n; i++) {
		ans[l] = arr[i];
		dfs(i + 1, l + 1);
	}

	return; 
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0,0);
	return 0;
}