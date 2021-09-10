#include <stdio.h>
#include <algorithm>
using namespace std;

struct strr {
	int w, v;
	strr(){}
	strr(int w, int v):
		w(w),v(v)
	{}
}arr[101];
int dp[101][100001]; // [i][w] i번째까지 고려 & 무게가 w일때

int main()
{
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].w, &arr[i].v);
	}
	for (int i = 1; i <= n; i++) {
		for(int j=1;j<=k;j++){
			if (j - arr[i].w >= 0) { //가져갈 수 있음
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].w] + arr[i].v);
				//가져가거나 안가져가거나 큰 것 선택
			}
			else {
				dp[i][j] = dp[i - 1][j];
				//못가져감
			}
		}
	}
	printf("%d\n", dp[n][k]);
	return 0;
}