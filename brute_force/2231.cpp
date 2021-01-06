#include <stdio.h>

int func(int n) {
	int ret = n;
	while(n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	int n; scanf("%d", &n);
	int ori = n;
	int ans = 0;
	while (n--) {
		int tmp = func(n);
		if (ori == tmp)
		{
			ans = n;
		}
	}
	printf("%d\n", ans);
	return 0;
}