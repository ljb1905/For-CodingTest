#include <stdio.h>

int main()
{
	int t; scanf("%d", &t);
	long long dp[101] = { 0,1,1,1,2,2 };
	for (int i = 4; i <= 100; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}
	while (t--) {
		int n; scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}