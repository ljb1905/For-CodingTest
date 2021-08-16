#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dis[20001];
struct s {
	int to, cost;
	s(int to, int cost):
		to(to),cost(cost)
	{}
};

int main() {
	int cnt = 0;
	int ans = 0;
	int n, m; scanf("%d %d", &n, &m);
	vector<int> v[20001];
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<s> q;
	q.push(s(1,1));
	int maxx = 0;
	while (!q.empty()) {
		int now = q.front().to;
		int val = q.front().cost;
		q.pop();
		if (dis[now] > 0) continue;
		dis[now] = val;
		maxx = max(maxx, val);
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (dis[next] == 0) {
				q.push(s(next, val + 1));
			}
		}
	}
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (!flag && dis[i] == maxx) {
			flag = true;
			ans = i;
		}
		if (dis[i] == maxx) cnt++;
	}
	printf("%d %d %d\n", ans, maxx-1, cnt);
	return 0;
}