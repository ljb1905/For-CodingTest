#include <stdio.h>

int main()
{
	int n; scanf("%d", &n);
	int dp[1001] = { 0 };
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	printf("%d\n", dp[n]);
}