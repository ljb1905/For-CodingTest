#include <stdio.h>

long long func(long long n, long long k, long long c) {
	if (k == 0)
		return 1;
	long long ret = func(n * n % c, k / 2, c)%c; 
	if (k % 2 == 1) {
		ret *= n;
		ret %= c;
	}
	return ret;
}

int main() {
	long long a, b, c; scanf("%lld %lld %lld", &a, &b, &c);
	printf("%lld\n", func(a, b, c));
	return 0;
}