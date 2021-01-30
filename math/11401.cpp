#include <stdio.h>

long long func(long long B, long long p, long long mod) {
	long long ret = 1;
	while (p > 0) {
		if (p % 2 == 1) {
			ret *= B;
			ret %= mod;
		}
		B *= B;
		B %= mod;
		p /= 2;
	}
	return ret;
}

int main() {
	int n, k; scanf("%d %d", &n, &k);
	long long p = 1000000007;
	long long A = 1;
	long long B = 1;
	for (int i = 1; i <= n; i++) { 
		A *= i;
		A %= p;
	}
	for (int i = 1; i <= k; i++) { 
		B *= i;
		B %= p;
	}
	for (int i = 1; i <= n-k; i++) {
		B *= i;
		B %= p;
	}
	B = func(B, p - 2, p);
	long long ans = A * B % p;
	printf("%lld\n", ans);
	return 0;
}