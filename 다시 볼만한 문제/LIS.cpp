#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001]; // i번째까지 가장 긴 부분 수열

int main()
{
	int n; scanf("%d", &n);
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxx = max(maxx, dp[i]);
	}
	printf("%d\n", maxx);
	return 0;
}