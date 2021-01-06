#include <stdio.h>

int arr[101];
int now[3];
int minn = 987654321;
int n,m;

void dfs(int idx, int cnt) {
	if (idx == n+1)
		return;
	if (cnt == 3) {
		int tmp = now[0] + now[1] + now[2];
		int val = m - tmp;
		if (val >= 0 && val < minn)
			minn = val;
		return;
	}
	now[cnt] = arr[idx];
	dfs(idx + 1, cnt + 1);
	dfs(idx + 1, cnt);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0, 0);
	printf("%d\n", m - minn);
	
	return 0;
}