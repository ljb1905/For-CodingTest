#include <stdio.h>
int main()
{
	int arr[201];
	int dp[201];
	int max = 0;
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i]) max = dp[i];
	}
	printf("%d\n", n - max);
	return 0;
}