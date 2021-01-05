#include <stdio.h>
#include <algorithm>
using namespace std;

bool notPrime[10001];

int main()
{
	for (int i = 2; i*i <= 10001; i++) {
		for (int j = i + i; j <= 10001; j += i) {
			notPrime[j] = true;
		}
	}
	int ans = 0;
	notPrime[1] = true;
	bool chkfst = false;
	int minn = 0;
	int a, b; scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++) {
		if (!notPrime[i]) {
			if (chkfst == false) {
				minn = i;
				chkfst = true;
			}
			ans += i;
		}
	}
	if (minn == 0)
		printf("-1\n");
	else {
		printf("%d\n%d", ans, minn);
	}
	return 0;
}