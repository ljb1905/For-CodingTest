#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct s {
	int ed, cost;
	s(){}
	s(int ed,int cost):
		ed(ed),cost(cost)
	{}
	bool operator < (const s& o)const {
		return cost > o.cost;
	}
};

int n, m; 
vector <s> v[801];
priority_queue <s> pq;

void dijk(bool* chk, int* dis, int stp) {
	for (int i = 0; i <= n; i++) {
		dis[i] = 987654321;
		chk[i] = false;
	}
	dis[stp] = 0;
	pq.push(s(stp, 0));
	while (!pq.empty()) {
		s now = pq.top();
		pq.pop();
		if (chk[now.ed] == true)
			continue;
		chk[now.ed] = true;
		for (int i = 0; i < v[now.ed].size(); i++) {
			s next = v[now.ed][i];
			if (dis[next.ed] > dis[now.ed] + next.cost) {
				dis[next.ed] = dis[now.ed] + next.cost;
				pq.push(s(next.ed, dis[next.ed]));
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(s(b, c));
		v[b].push_back(s(a, c));
	}
	int p1, p2; scanf("%d %d", &p1, &p2);
	int dis1[801];
	bool chk1[801];
	dijk(chk1, dis1, p1);
	int dis2[801];
	bool chk2[801];
	dijk(chk2, dis2, p2);
	
	int ans1;
	if (dis1[1] == 987654321 || dis1[p2] == 987654321 || dis2[n] == 987654321) {
		ans1 = 987654321;
	}
	else {
		ans1 = dis1[1] + dis1[p2] + dis2[n];
	}
	int ans2;
	if (dis2[1] == 987654321 || dis2[p1] == 987654321 || dis1[n] == 987654321) {
		ans2 = 987654321;
	}
	else {
		ans2 = dis2[1] + dis2[p1] + dis1[n];
	}
	int ans = min(ans1, ans2);
	if (ans >= 987654321)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}