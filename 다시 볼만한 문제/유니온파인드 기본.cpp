#include <stdio.h>
#include <algorithm>
using namespace std;

int cc[1000001];
int find(int now)
{
	if (cc[now] == now) return now;
	return cc[now] = find(cc[now]);
}
void uni(int a, int b)
{
	a = find(a);
	b = find(b);
	cc[a] = b;
}

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) cc[i] = i;
	for (int i = 0; i < m; i++)
	{
		int a, b, c; scanf("%d %d %d", &a, &b,&c);
		if(a==0) uni(b, c);
		else
		{
			if (find(b) == find(c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}