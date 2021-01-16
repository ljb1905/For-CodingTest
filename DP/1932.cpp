#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[501][501];
int dp[501][501];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j-1], dp[i - 1][j]) + arr[i][j];
		}
	}
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		maxx = max(maxx, dp[n][i]);
	}
	printf("%d\n", maxx);
	return 0;
}