#include <stdio.h>
#include <algorithm>
using namespace std;

long long arr[1000001];
long long maxx;

int main() {
	long long n, m; scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
		maxx = max(maxx, arr[i]);
	}
	long long l = 1;
	long long r = maxx;
	long long mid = (l + r) / 2;
	while (l <= r) {
		mid = (l + r) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			if (mid > arr[i])
				continue;
			cnt += arr[i] - mid;
		}
		if (cnt >= m) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%lld\n", r);
	return 0;
}