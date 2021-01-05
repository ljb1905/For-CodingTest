#include <stdio.h>

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		int h, w, n; scanf("%d %d %d", &h, &w, &n);
		int quo = n / h + 1;
		int rem = n % h;
		if (rem == 0) {
			quo--;
			rem = h;
		}
		printf("%d%02d\n", rem, quo);
	}
	return 0;
}