#include <stdio.h>

long long dp[31][31];

void func() {
	for (int i = 0; i <= 30; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	return;
}

int main()
{
	func();
	int t; scanf("%d", &t);
	while (t--) {
		int n, m; scanf("%d %d", &n, &m);
		printf("%lld\n", dp[m][n]);
	}
	return 0;
}