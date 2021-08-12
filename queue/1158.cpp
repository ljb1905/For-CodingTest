#include <stdio.h>
#include <queue>
using namespace std;

queue<int> q;
queue<int> ans;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) q.push(i);
	int cnt = 0;
	while (cnt < n) {
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		ans.push(q.front());
		q.pop();
		cnt++;
	}
	printf("<%d", ans.front());
	ans.pop();
	while (ans.size() >= 2) {
		printf(", %d", ans.front());
		ans.pop();
	}
	if (ans.size() == 1) {
		printf(", %d>\n", ans.front());
	}
	else printf(">\n");
	return 0;
}