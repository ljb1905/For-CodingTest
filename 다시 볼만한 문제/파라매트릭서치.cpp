#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	long long n,m; scanf("%lld %lld", &n, &m);
	long long l = 1;
	long long r = m;
	long long mid = (l + r) / 2;
	while (l <= r) {
		mid = (l + r) / 2; 
		long long cnt = 0;
		for (int i = 1; i <= n; i++) {//x보다 큰수 찾기
			cnt += min((mid / i), n);
		}
		if (cnt >= m) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	printf("%lld\n", l);
	return 0;
}