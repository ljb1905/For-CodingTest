#include <stdio.h>

int n, m;
int arr[10];

void dfs(int cnt){
	if (cnt == m) {
		if (arr[1] == 0)
			return;
		for (int i = 1; i <= m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = arr[cnt]; i <= n; i++) {
		arr[cnt+1] = i;
		dfs(cnt + 1);
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	dfs(0);
	return 0;
}