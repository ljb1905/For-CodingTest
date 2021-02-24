#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int par[200001];
int find(int now)
{
	if (par[now] == now) return now;
	return par[now] = find(par[now]);
}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	par[b] = a;
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		map<string, int> m;
		int n; scanf("%d", &n);
		int cnt = 1;
		for (int i = 0; i < n; i++)
		{
			char arr[21], brr[21];
			scanf("%s %s", arr, brr);
			if (m.find(arr) == m.end())
			{
				m.insert(pair<string, int>(arr, cnt));
				par[cnt] = cnt;
				cnt++;
			}
			if (m.find(brr) == m.end())
			{
				m.insert(pair<string, int>(brr, cnt));
				par[cnt] = cnt;
				cnt++;
			}
			int asdf = m.find(arr)->second;
			uni(m.find(arr)->second, m.find(brr)->second);
			int tmp = find(asdf);
			int ans = 0;
			for (int i = 1; i < cnt; i++)
				if (find(i) == tmp) ans++;
			printf("%d\n", ans);
		}
	}
	return 0;
}