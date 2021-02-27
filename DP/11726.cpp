#include <stdio.h>

int main()
{
	int arr[1001] = { 0,1 ,2 };
	int n; scanf("%d", &n);
	for (int i = 3; i <= n; i++) arr[i] = (arr[i - 1] + arr[i - 2])%10007;
	printf("%d\n", arr[n]);
	return 0;
}