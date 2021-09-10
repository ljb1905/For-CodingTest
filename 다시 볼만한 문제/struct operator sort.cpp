#include <stdio.h>
#include <algorithm>
using namespace std;

struct strr {
	int st, ed;
	strr(){}
	strr(int st, int ed)
		:st(st),ed(ed)
	{}
	bool operator < (const strr& o)const {
		return st < o.st;
	}
}arr[101];

int dp[101];

int main()
{
	int n; scanf("%d", &n);
	int maxx = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].st, &arr[i].ed);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i].ed > arr[j].ed) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxx = max(maxx, dp[i]);
	}
	printf("%d\n", n - maxx);
	return 0;
}