#include <stdio.h>

int dp[1011][1011];

int main()
{
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			dp[i][j] %= 10007;
		}
	}
	printf("%d\n", dp[n][k]);
	
	return 0;
}