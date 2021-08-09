#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int dis[1001];
int bt[1001];
int st, ed;
bool chk[1001];

struct s {
	int ed, cost;
	s() {}
	s(int ed, int cost) :
		ed(ed), cost(cost)
	{}
	bool operator <(const s& o)const {
		return cost > o.cost;
	}
};
vector<s> v[1001];
priority_queue<s> pq;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(s(b, c));
	}
	scanf("%d %d", &st, &ed);
	for (int i = 1; i <= n; i++) dis[i] = 987654321;
	dis[st] = 0;
	pq.push(s(st, 0));
	while (!pq.empty()) {
		s now = pq.top();
		pq.pop();
		if (chk[now.ed]) continue;
		chk[now.ed] = true;
		for (int i = 0; i < v[now.ed].size(); i++) {
			s next = v[now.ed][i];
			if (dis[next.ed] > dis[now.ed] + next.cost) {
				dis[next.ed] = dis[now.ed] + next.cost;
				pq.push(s(next.ed, dis[next.ed]));
				bt[next.ed] = now.ed;
			}
		}
	}
	vector<int> bef;
	int tmp = ed;
	int cnt = 0;
	while (tmp != st) {
		bef.push_back(tmp);
		tmp = bt[tmp];
		cnt++;
	}
	printf("%d\n%d\n%d ", dis[ed], cnt + 1, st);
	for (int i = bef.size() - 1; i > 0; i--) {
		printf("%d ", bef[i]);
	}
	if (bef.size() != 0) printf("%d\n", bef[0]);
	return 0;
}