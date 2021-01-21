#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

int dis[100001];
int val[100001];
int minn[100001];

int main()
{
	int n; scanf("%d", &n);
	int minval = INT_MAX;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d", &dis[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
		minval = min(minval, val[i]);
		minn[i] = minval;
	}
	long long ans = 0;
	for (int i = 0; i < n-1; i++) {
		ans += (long long)dis[i] * minn[i];
	}
	printf("%lld\n", ans);
	return 0;
}