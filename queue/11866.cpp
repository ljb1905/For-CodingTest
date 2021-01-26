#include <stdio.h>
#include <queue>
using namespace std;

bool chk[1001];
queue <int> q;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	int cnt = 0;
	int idx = 0;
	while (cnt < n) {
		int kcnt = 0;
		while (kcnt < k) {
			idx++;
			idx %= n;
			if (chk[idx] == false) {
				kcnt++;
			}
		}
		chk[idx] = true;
		if (idx == 0)
			q.push(n);
		else
			q.push(idx);
		cnt++;
	}
	printf("<");
	while (q.size() != 1) {
		printf("%d, ", q.front());
		q.pop();
	}
	printf("%d>\n", q.front());
	return 0;
}