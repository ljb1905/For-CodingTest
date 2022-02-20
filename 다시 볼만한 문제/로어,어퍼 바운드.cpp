#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[500001];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int a; scanf("%d", &a);
		int st = lower_bound(arr, arr + n, a) - arr;
		int ed = upper_bound(arr, arr + n, a) - arr;
		printf("%d ", ed - st);
	}
	return 0;
}

Lower Bound는 '원하는 값 k 이상이 처음 나오는 위치를 찾는 과정' 이며, Upper Bound는 '원하는 값 k를 초과한 값이 처음 나오는 위치를 찾는 과정'이다. 