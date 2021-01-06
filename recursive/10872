#include <stdio.h>

long long dfs(long long n) {
	if (n == 1 || n==0)
		return 1;
	return n * dfs(n - 1);
}

int main()
{
	long long n; scanf("%lld", &n);
	printf("%lld\n", dfs(n));
	return 0;
}