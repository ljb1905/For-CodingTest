#include <stdio.h>
long long arr[1000001],brr[1000001];
int main ()
{
	int a,b,c; scanf("%d %d %d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		scanf("%lld",&brr[i]);
		for(int j=i;j<=a;j+=j&(-j))
			arr[j]+=brr[i];
	}
	for(int i=1;i<=b+c;i++)
	{
		int n,m; long long k; scanf("%d %d %lld",&n,&m,&k);
		long long inc;
		if(n==1)
		{
			inc = k-brr[m];
			for(int j=m;j<=a;j+=j&(-j))
			arr[j]+=inc;
			brr[m]=k;
		}
		else if(n==2)
		{
			long long tmp1=0;
			for(long long j=k;j>0;j-=j&(-j))
				tmp1+=arr[j];
			long long tmp2 = 0;
			for(int j=m-1;j>0;j-=j&(-j))
				tmp2+=arr[j];
			long long ans = tmp1-tmp2;
			printf("%lld\n",ans);
		}
	}
	return 0;
}