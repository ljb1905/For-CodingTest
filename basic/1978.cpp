#include <stdio.h>
#include <algorithm>
using namespace std;

bool notPrime[1001];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 2; i*i <= 1001; i++) {
		for (int j = i + i; j <= 1001; j += i) {
			notPrime[j] = true;
		}
	}
	int ans = 0;
	notPrime[1] = true;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (!notPrime[a]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}