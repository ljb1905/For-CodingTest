#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int arr[500001];
int brr[500001];
long long ans;

void fun(int l, int r)
{
	if (r - l <= 1)
	{
		if (arr[l] > arr[r])
		{
			ans++;
			swap(arr[l], arr[r]);
		}
		return;
	}
	int mid = (l + r) / 2;
	fun(l, mid);
	fun(mid + 1, r);
	int i = l;
	int lef = l, rig = mid + 1;
	while (lef <= mid && rig <= r)
	{
		if (arr[lef] > arr[rig])
		{
			ans += (long long)(mid + 1 - lef);
			brr[i++] = arr[rig++];
		}
		else
			brr[i++] = arr[lef++];
	}
	while (lef <= mid) brr[i++] = arr[lef++];
	while (rig <= r) brr[i++] = arr[rig++];
	for (int i = l; i <= r; i++)
		arr[i] = brr[i];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	fun(0, n - 1);
	printf("%lld\n", ans);
	return 0;
}