#include <stdio.h>
#include <map>
using namespace std;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int sum[10001] = { 0, };
	map<int, int> mmap;
	for (int i = 0; i < n; i++) {
		int tmp; scanf("%d", &tmp);
		if (i == 0) sum[i] = tmp;
		else {
			sum[i] = sum[i - 1] + tmp;
		}
		mmap[sum[i]]++;
	}
	mmap[0]++;
	int ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		int now = sum[i];
		int finval = now - m;
		if (mmap.count(finval)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}