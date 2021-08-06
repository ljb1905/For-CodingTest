#include <stdio.h>

int GCD(int a, int b) { return a % b == 0 ? b : GCD(b, a % b); }

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int a, b; scanf("%d %d", &a, &b);
		int gcd = GCD(a, b);
		printf("%d %d\n", a * b / gcd, gcd);
	}
	return 0;
}