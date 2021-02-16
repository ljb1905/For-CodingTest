#include <stdio.h>

int main ()
{
	int dis[401][401];
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dis[i][j]=987654321;
		}
	}
	while(m--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		dis[a][b]=c;
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j];
			}
		}
	}
	int ans=987654321;
	bool sw=false;
	for(int i=1;i<=n;i++)
	{
		if(ans>dis[i][i] && dis[i][i]!=987654321)
		{
			sw=true;
			ans=dis[i][i];
		}
	}
	if(sw) printf("%d\n",ans);
	else printf("-1\n");	
	return 0;
}