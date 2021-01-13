#include <stdio.h>

int n, m;
int arr[10];
bool chk[10];

void dfs(int cnt){
	if (cnt == m) {
		for (int i = 1; i <= m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = arr[cnt]+1; i <= n; i++) {
		if (chk[i])
			continue;
		arr[cnt+1] = i;
		chk[i] = true;
		dfs(cnt + 1);
		chk[i] = false;
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	dfs(0);
	return 0;
}