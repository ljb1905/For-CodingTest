#include <stdio.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int arr[17][17];
int dp[17][1 << 17];
int n;

int dfs(int x, int chk)
{
	if (x == 1 && chk == (1 << (n)) - 1) return 0;
	int &tmp = dp[x][chk];
	if (tmp != -1) return tmp;
	tmp = 987654321;
	for (int i = 1; i <= n; i++)
	{
		if ((chk & (1 << (i-1))) == 0 && arr[x][i] > 0)
		{
			tmp = min(tmp, arr[x][i]+dfs(i, (chk | (1 << (i-1)))));
		}
	}
	return tmp;
}


int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &arr[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(1, 0));
	return 0;
}