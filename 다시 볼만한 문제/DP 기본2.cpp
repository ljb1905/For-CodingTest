#include <stdio.h>

int d[10001];
int arr[101][2];

int main ()
{
	int t,n;
	scanf("%d %d",&t,&n);
	d[0]=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i][0],&arr[i][1]);
		for(int k=t;k>=arr[i][0];k--)
		{
			for(int j=1;j<=arr[i][1];j++)
				if(arr[i][0]*j <=k) d[k]+=d[k-j*arr[i][0]];
		}
	}
	printf("%d\n",d[t]);
	return 0;
}