#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int n, m, k, st, g, h;
struct s {
	int ed, cost;
	bool thchk;
	s(){}
	s(int ed, int cost, bool thchk) 
		:ed(ed),cost(cost),thchk(thchk)
	{}
	bool operator < (const s& o)const {
		return cost > o.cost;
	}
};
priority_queue<s> pq;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		vector <s> v[2001];
		int dis[2001] = { 0, };
		bool chk[2001] = { 0, };
		bool inp[2001] = { 0, };
		bool ans[2001] = { 0, };
		scanf("%d %d %d", &n, &m, &k);
		scanf("%d %d %d", &st, &g, &h);
		for (int i = 0; i < m; i++) {
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			if ((a == g && b == h) || (a == h && b == g)) {
				v[a].push_back(s(b, c, true));
				v[b].push_back(s(a, c, true));
			}
			else {
				v[a].push_back(s(b, c, false));
				v[b].push_back(s(a, c, false));
			}
		}
		for (int i = 0; i < k; i++) {
			int a; scanf("%d", &a);
			inp[a] = true;
		}
		pq.push(s(st, 0, false));
		while (!pq.empty()) {
			s now = pq.top();
			pq.pop();
			if (chk[now.ed] == true) 
				continue;
			chk[now.ed] = true;
			if (now.thchk == true) {
				ans[now.ed] = true;
			}
			for (int i = 0; i < v[now.ed].size(); i++) {
				s next = v[now.ed][i];
				if (dis[next.ed] > dis[now.ed] + next.cost || dis[next.ed]==0) {
					dis[next.ed] = dis[now.ed] + next.cost;
					pq.push(s(next.ed, dis[next.ed], now.thchk));
				}
			}
		}
		for (int i = 0; i <= n; i++) {
			if (ans[i] == true && inp[i] == true) {
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}