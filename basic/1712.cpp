#include <stdio.h>

int main()
{
	long long a, b, c; scanf("%lld %lld %lld",&a,&b,&c);
	long long ans = 0;
	long long tmp = c - b;
	if (tmp <= 0) {
		ans = -1;
	}
	else {
		ans = a / tmp;
		ans++;
	}
	printf("%lld\n", ans);
	return 0;
}