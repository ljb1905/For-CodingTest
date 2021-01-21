#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[1001];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (n - i) * arr[i];
	}
	printf("%d\n", ans);
	return 0;
}