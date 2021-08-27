#include <stdio.h>

bool chk[101];

int main() {
	int n; scanf("%d", &n);
	int num = 2;
	while (num <= 100) {
		chk[num] = true;
		num *= 2;
	}
	chk[1] = true;
	while (!chk[n])
		n--;
	printf("%d\n", n);
	return 0;
}