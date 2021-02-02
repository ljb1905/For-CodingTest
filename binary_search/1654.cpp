#include <stdio.h>
#include <limits.h>
#include <algorithm>
using namespace std;

long long arr[10001];
long long maxx = 0;

int main() {
	long long k, n; scanf("%lld %lld", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%lld", &arr[i]);
		maxx = max(maxx, arr[i]);
	}
	long long l = 1;
	long long r = maxx;
	long long mid = (l+r) / 2;
	while (l <= r) {
		mid = (l+r) / 2;
		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += arr[i] / mid;
		}
		if (cnt >= n) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%lld\n", r);
	return 0;
}