#include <stdio.h>

int main()
{
	int n; scanf("%d", &n);
	int val = 1;
	int ans = 0;
	int tmp = 0;
	int mul = 1;
	while (tmp < n) {
		ans++;
		val += tmp;
		tmp += mul;
		if (mul == 1)
			mul = 6;
		else mul += 6;
	}
	printf("%d\n", ans);
	return 0;
}