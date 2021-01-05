#include <stdio.h>

int main()
{
	int t; scanf("%d", &t);
	while (t -- ) {
		int k, n; scanf("%d %d", &k, &n);
		int arr[15][15] = { 0, };
		for (int i = 1; i <= n; i++) {
			arr[0][i] = i;
			arr[i][1] = 1;
		}
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++) {
				arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
			}
		}
		printf("%d\n", arr[k][n]);

	}
	return 0;
}