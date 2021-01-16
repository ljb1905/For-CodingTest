#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[310];
int dp[310][3];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + arr[i];
		dp[i][2] = dp[i - 1][1] + arr[i];
	}
	printf("%d\n", max(dp[n][1], dp[n][2]));
	return 0;
}