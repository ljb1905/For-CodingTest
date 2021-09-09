#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
#include <functional>
#include <algorithm>
using namespace std;

struct strr {
	int ed, cost;
	strr(){}
	strr(int ed,long long cost):
		ed(ed),cost(cost)
	{}
	bool operator <(const strr & o)const {
		return cost > o.cost;
	}
};

int n, m, t;
int s, g, h;

void dijk(bool* chk, long long* dis, vector<strr> v[2001], int st) {
	priority_queue<strr> pq;
	pq.push(strr(st, 0));
	while (!pq.empty()) {
		strr now = pq.top();
		pq.pop();
		if (chk[now.ed] == true)
			continue;
		chk[now.ed] = true;
		for (int i = 0; i < v[now.ed].size(); i++) {
			strr next = v[now.ed][i];
			if (dis[next.ed] > dis[now.ed] + next.cost) {
				dis[next.ed] = dis[now.ed] + next.cost;
				pq.push(strr(next.ed, dis[next.ed]));
			}
		}
	}
}

int main() {
	int tc; scanf("%d", &tc);
	while (tc--) {
		vector<strr> v[2001];
		priority_queue<int,vector<int>, greater<int>> ans;
		bool chk[2001] = { false, };
		long long dis[2001] = { 0, };
		bool chk2[2001] = { false, };
		long long dis2[2001] = { 0, };
		bool chk3[2001] = { false, };
		long long dis3[2001] = { 0, };
		scanf("%d %d %d", &n, &m, &t);
		scanf("%d %d %d", &s, &g, &h);
		for (int i = 1; i <= n; i++) {
			dis[i] = INT_MAX;
			dis2[i] = INT_MAX;
			dis3[i] = INT_MAX;
		}
		for (int i = 0; i < m; i++) {
			int a, b, c; scanf("%d %d %d", &a, &b, &c);
			v[a].push_back(strr(b, c));
			v[b].push_back(strr(a, c));
		}
		dis[s] = 0;
		dijk(chk, dis, v, s); //s에서 출발
		dis2[g] = 0;
		dijk(chk2, dis2, v, g); //g에서 출발
		dis3[h] = 0;
		dijk(chk3, dis3, v, h); //h에서 출발

		for (int i = 0; i < t; i++) {
			int a; scanf("%d", &a);
			long long tmp = dis[a];
			long long comp[2];
			comp[0] = dis[g] + dis2[h] + dis3[a]; // 같을떄?
			comp[1] = dis[h] + dis3[g] + dis2[a];
			long long tmp2 = min(comp[0], comp[1]);
			if (tmp == INT_MAX)
				continue;
			if (tmp == tmp2) {
				ans.push(a);
			}
		}
		while (ans.size() > 1) {
			printf("%d ", ans.top());
			ans.pop();
		}
		if (ans.size() == 1) {
			printf("%d\n", ans.top());
			ans.pop();
		}
	}
	return 0;
}