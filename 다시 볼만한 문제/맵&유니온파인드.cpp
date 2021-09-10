#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int par[200001];
int cntt[200001];
int find(int now)
{
	if (par[now] == now) return now;
	return par[now] = find(par[now]);
}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if (par[b] != a) {
		par[b] = a;
		cntt[b] += cntt[a];
		cntt[a] = cntt[b];
	}
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
			if (m.find(arr) == m.end()) // arr로 받은 입력이 없을때
			{
				m.insert(pair<string, int>(arr, cnt));
				par[cnt] = cnt;
				cntt[cnt] = 1;
				cnt++;
			}
			if (m.find(brr) == m.end()) // brr로 받은 입력이 없을때
			{
				m.insert(pair<string, int>(brr, cnt));
				par[cnt] = cnt;
				cntt[cnt] = 1;
				cnt++;
			}
			uni(m.find(arr)->second, m.find(brr)->second);
			int asdf = find(m.find(arr)->second);
			printf("%d\n", cntt[asdf]);
		}
	}
	return 0;
}