#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct s {
	int st, ed, cost;
	s(){}
	s(int st, int ed, int cost) :
		st(st), ed(ed), cost(cost)
	{}
};
vector <s> v;
long long dis[501];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		v.push_back(s(a, b, c));
	}
	for (int i = 1; i <= n; i++) {
		dis[i] = 987654321;
	}
	dis[1] = 0;
	for (int i = 0; i < n; i++) {
		bool chk = false;
		for (int j = 0; j < m; j++) {
			s now = v[j];
			if (dis[now.st] == 987654321)
				continue;
			if (dis[now.ed] > dis[now.st] + now.cost) {
				dis[now.ed] = dis[now.st] + now.cost;
				chk = true;
			}
		}
		if (i == n - 1 && chk == true)
		{
			printf("-1\n");
			return 0;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (dis[i] == 987654321) printf("-1\n");
		else printf("%d\n", dis[i]);
	}
	return 0;
}