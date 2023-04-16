#include <stdio.h>
#include <algorithm>
using namespace std;

long long ori[1000001];
long long arr[1000001];
int n, m;

long long calc(int k) {
	long long ret = 0;
	for (long long j = k; j > 0; j -= j & (-j))
		ret += arr[j];
	return ret;
}
void update(int k, long long c) {
	long long inc = c - ori[k];
	for (long long j = k; j <= n; j += j & (-j))
		arr[j] += inc;
	ori[k] = c;
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if (a == 0) {
			long long inp1 = calc(max(b, c));
			long long inp2 = calc(min(b, c) - 1);
			printf("%lld\n", inp1 - inp2);
		}
		else {
			update(b, c);
		}
	}
	return 0;
}