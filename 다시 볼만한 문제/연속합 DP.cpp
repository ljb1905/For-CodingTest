#include <stdio.h>
#include <limits.h>

int arr[100001];
int max = INT_MIN;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i < n; i++)
	{
		if (arr[i - 1] + arr[i] > arr[i]) arr[i] = arr[i - 1] + arr[i];
		if (arr[i - 1] > max) max = arr[i - 1];
	}
	if (arr[n - 1] > max)max = arr[n - 1];
	printf("%d", max);
	return 0;
}