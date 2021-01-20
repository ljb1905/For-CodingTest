#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char arr[1001];
char brr[1001];
int dp[1001][1001];

int main()
{
	scanf("%s %s", arr + 1, brr + 1);
	int l1 = strlen(arr+1);
	int l2 = strlen(brr+1);
	for (int i = 1; i <= l1; i++) {
		for (int j = 1; j <= l2; j++) {
			if (arr[i] == brr[j]) { // 같을때는 대각선에서 +1해서 가지옴
				dp[i][j] = dp[i - 1][j - 1] + 1; 
			}
			else { // 다를때는 위나 옆에서 큰 것 가지고 오기
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	printf("%d\n", dp[l1][l2]);
	return 0;
}