#include <stdio.h>
#include <queue>
using namespace std;

queue<long long> q;

int main() {
	long long n; scanf("%lld", &n);
	if (n / 10 == 0) {
		printf("%lld\n", n);
		return 0;
	}
	if (n > 1022) {
		printf("-1\n");
		return 0;
	}
	long long idx = 9;
	long long now = 0;
	long long ans = -1;
	for (int i = 1; i <= 9; i++) {
		q.push(i);
	}
	bool flag = false;
	while (idx <n || idx < 1000001) {
		long long tmp = q.front();
		q.pop();
		long long val = tmp % 10;
		for (int i = 0; i < val; i++) {
			now = tmp * 10 + i;
			q.push(now);
			idx++;
			if (idx == n) {
				flag = true;
				ans = now;
				break;
			}
		}
		if (flag) break;
	}
	printf("%lld\n", ans);
	return 0;
}