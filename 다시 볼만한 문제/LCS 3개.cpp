#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int ans[101][101][101];

int main()
{
	char arr[101], brr[101], crr[101]; scanf("%s %s %s", arr, brr, crr);
	int n = strlen(arr), m = strlen(brr), l = strlen(crr);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= l; k++)
			{
				if (arr[i - 1] == brr[j - 1] && brr[j - 1] == crr[k - 1]) ans[i][j][k] = ans[i - 1][j - 1][k - 1] + 1;
				else ans[i][j][k] = max(ans[i - 1][j][k], max(ans[i][j - 1][k], ans[i][j][k - 1]));
			}
		}
	}
	printf("%d\n", ans[n][m][l]);
	return 0;
}