#include <stdio.h>
#include <algorithm>
#include <string.h>
#define maxx 0x7f
#define max 0x7f7f7f7f
using namespace std;


int arr[101][101];

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	memset(arr,maxx , sizeof(arr));
	for (int i = 1; i <= n; i++)
		arr[i][i] = 0;
	for (int i = 0; i < m; i++)
	{
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		arr[a][b] = min(arr[a][b], c);
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (arr[i][k] == max || arr[k][j] == max) continue;
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == max) printf("0 ");
			else printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}