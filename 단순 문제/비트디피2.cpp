//백준 1029

#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[17][17];
int dp[17][2 << 17];
int n;

int dfs(int now, int buy, int stat) {
	int& ret = dp[now][stat];
	if (ret) return ret;
	for (int i = 1; i < n; i++) {
		if (!(stat & (1 << i))) {
			if (buy <= arr[now][i]) {
				ret = max(ret, dfs(i, arr[now][i], stat | (1 << i)) + 1);
			}
		}
	}
	return ret;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	printf("%d\n",dfs(0, 0, 1)+1);
	return 0;
}