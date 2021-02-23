#include <stdio.h>

int cc[201];

int find(int n)
{
	if (cc[n] == n) return n;
	return cc[n] = find(cc[n]);
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
	for (int i = 1; i <= n; i++)
		cc[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int a; scanf("%d", &a);
			if (a == 1) uni(i, j);
		}
	int val;
	bool ans = true;
	for (int i = 1; i <= m; i++) {
		int a; scanf("%d", &a);
		find(a);
		if(i==1)
			val = cc[a];
		else if (val != cc[a]) {
			ans = false;
		}
	}	
	if (ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}