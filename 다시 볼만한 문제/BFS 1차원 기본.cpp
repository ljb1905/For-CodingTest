#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

struct s
{
	int day, sta, i, j;
	s(){}
	s(int day,int sta, int i, int j)
		:day(day),sta(sta),i(i),j(j)
	{}
}arr[1002][1002];
queue<s> q;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

int main()
{
	int n, m; scanf("%d %d", &m, &n);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &arr[i][j].sta);
			if(arr[i][j].sta==1)
				q.push(s(0, 1, i, j));
		}			
	for (int i = 0; i <= n + 1; i++)
	{
		arr[i][0].sta = 1;
		arr[i][m + 1].sta = 1;
	}
	for (int j = 0; j <= m + 1; j++)
	{
		arr[0][j].sta = 1;
		arr[n + 1][j].sta = 1;
	}
	while (!q.empty())
	{
		s now = q.front();
		q.pop();
		if (ans < now.day) ans = now.day;
		for (int i = 0; i < 4; i++)
		{
			int nexti = now.i + dy[i];
			int nextj = now.j + dx[i];
			if (arr[nexti][nextj].sta == 0)
			{
				q.push(s(now.day + 1, 1, nexti, nextj));
				arr[nexti][nextj].sta = 1;
			}						
		}
	}
	bool pos = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (arr[i][j].sta == 0) pos = false;
	if (pos) printf("%d\n", ans);
	else printf("-1\n");
	return 0;
}