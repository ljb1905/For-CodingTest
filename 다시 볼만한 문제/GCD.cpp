#include <stdio.h>
#include <algorithm>
using namespace std;

int GCD(int a, int b) { return a % b == 0 ? b : GCD(b, a % b); }
int main()
{
	int a, b; scanf("%d %d", &a, &b);
	if (a < b) swap(a, b);
	int ans = GCD(a, b);
	printf("%d\n%d\n", ans, a * b / ans);
	return 0;
}