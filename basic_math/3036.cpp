#include <stdio.h>

int arr[101];
int GCD(int a, int b) { return a % b == 0 ? b : GCD(b, a % b); }

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i < n; i++) {
		int tmp = GCD(arr[0], arr[i]);
		printf("%d/%d\n", arr[0] / tmp, arr[i] / tmp);
	}
	return 0;
}