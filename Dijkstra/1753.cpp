#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct s {
	int ed, cost;
	s(){}
	s(int ed,int cost):
		ed(ed),cost(cost)
	{}
	bool operator < (const s& o) const{
		return cost > o.cost;
	}
};
vector <s> v[20001];
priority_queue <s> pq;
int dis[20001];
bool chk[20001];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int stp; scanf("%d", &stp);
	for (int i = 0; i <= n; i++) {
		dis[i] = 987654321;
	}
	dis[stp] = 0;
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(s(b, c));
	}
	pq.push(s(stp,0));
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
				pq.push(s(next.ed,dis[next.ed]));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dis[i] == 987654321)
			printf("INF\n");
		else {
			printf("%d\n", dis[i]);
		}
	}
	return 0;
}