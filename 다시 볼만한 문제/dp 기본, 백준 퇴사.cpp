#include <stdio.h>
#include <algorithm>
using namespace std;

int dp[16];
int t[16];
int val[16];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t[i], &val[i]);
	}
	for (int i = 0; i <= n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			dp[i] = max(dp[i], dp[j]);
			if (t[j] + j == i) {
				dp[i] = max(dp[i], dp[j] + val[j]);
			}
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}