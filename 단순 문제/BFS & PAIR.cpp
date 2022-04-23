#include <stdio.h>

int chk(int n) {
	int ret = 0;
	while (1) {
		if (ret == 3)
			return 3;
		if (n == 0) {
			return ret;
		}
		int rem = n % 10;
		if (rem == 6) {
			ret++;
		}
		else
			ret = 0;
		n /= 10;
	}
}

int main()
{
	int n; scanf("%d", &n);
	int cnt = 0;
	int a = 666;
	while (1) {
		if (chk(a) == 3) {
			cnt++;
		}
		if (cnt == n)
			break;
		a++;
	}
	printf("%d\n", a);
	return 0;
}