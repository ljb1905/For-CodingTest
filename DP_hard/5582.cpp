#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char arr[4001], brr[4001];
int crr[4001][4001];
int main()
{
	arr[0] = 1, brr[0] = 1;
	scanf("%s %s", arr+1, brr+1);
	int n = strlen(arr) - 1, m = strlen(brr) - 1;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (arr[i] == brr[j])
			{
				crr[i][j] = crr[i - 1][j - 1] + 1;
				if (crr[i][j] > ans) ans = crr[i][j];
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}