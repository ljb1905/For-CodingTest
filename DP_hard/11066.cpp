#include <stdio.h>

int dp[501][501], sum[501] = { 0 };

int func(int a, int b) 
{
	if (a == b) return 0;
	int& c = dp[a][b];
	if (c != -1) return c;
	for (int k = a; k < b; k++) 
	{
		int temp = func(a, k) + func(k + 1, b) + sum[b] - sum[a - 1];
		if (c == -1 || c > temp)
			c = temp;
	}
	return c;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--) 
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = -1;
		for (int i = 1; i <= n; i++) sum[i] = 0;
		int arr[501];
		for (int i = 1; i <= n; i++) 
		{
			scanf("%d", &arr[i]);
			sum[i] = sum[i - 1] + arr[i];
		}
		printf("%d\n", func(1, n));
	}
	return 0;
}