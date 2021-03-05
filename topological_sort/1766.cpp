#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[32001];
priority_queue<int,vector<int>,greater<int>> pq;
int inn[32001];

int main()
{
	int n,m; scanf("%d %d", &n,&m);
	for (int i = 1; i <= m; i++)
	{
		int a, b; scanf("%d %d", &a, &b);
		v[a].push_back(b);
		inn[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (inn[i] == 0) pq.push(i);
	while (!pq.empty())
	{
		int now = pq.top();
		pq.pop();
		printf("%d ", now);
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i];
			inn[next]--;
			if (inn[next] == 0) pq.push(next);
		}
	}
	
	return 0;
}