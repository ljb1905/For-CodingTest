#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001]; // i번째까지 가장 긴 증가 부분 수열
int dp2[1001]; // i번째까지 가장 긴 감소 부분 수열

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
	}
	for (int i = n; i >= 1; i--) {
		dp2[i] = 1;
		for (int j = n; j > i; j--) {
			if (arr[j] < arr[i]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		maxx = max(maxx, dp[i] + dp2[i]);
	}
	printf("%d\n", maxx-1);
	return 0;
}