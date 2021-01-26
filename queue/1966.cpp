#include <stdio.h>
#include <queue>
#include <functional> // functional -> less
#include <vector>
using namespace std;

struct s {
	int idx, val;
	s(){}
	s(int idx, int val) :
		idx(idx), val(val)
	{}
};

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		priority_queue <int, vector<int>, less<int>> pq; // max heap
		queue <s> q; //queue
		int ans = 1;
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			q.push(s(i, a));
			pq.push(a);
		}
		while (!q.empty()) {
			s now = q.front();
			if (now.idx == m && now.val >= pq.top()) {
				break;
			}
			if (now.val < pq.top()) {
				q.pop();
				q.push(now);
			}
			else {
				q.pop();
				pq.pop();
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}