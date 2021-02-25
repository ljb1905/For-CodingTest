#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
int arr[501][501];
int dp[501][501];

bool check(int i,int j,int ni,int nj)
{
	int nnum = arr[ni][nj];
	int num = arr[i][j];
	if (nnum < num) return true;
	else return false;
}

int dfs(int i, int j)
{
	if (dp[i][j] != -1) return dp[i][j];
	else dp[i][j] = 0;
	if (dp[i][j] != 0)
		return dp[i][j];
	for (int a = 0; a < 4; a++)
	{
		int ni = i + dy[a];
		int nj = j + dx[a];
		if (check(i, j, ni, nj))
			dp[i][j] += dfs(ni,nj);
	}
	return dp[i][j];
}

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	memset(arr, 0x7f, sizeof(arr));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j]);
			dp[i][j] = -1;
		}				
	dp[n][m] = 1;
	dfs(1, 1);		
	printf("%d\n", dp[1][1]);
		
	return 0;
}