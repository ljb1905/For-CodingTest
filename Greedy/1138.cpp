#include <stdio.h>

int arr[11];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		for (int j = 1; j <= n; j++) {
			if (arr[j] != 0) continue;
			if (a == 0) {
				arr[j] = i;
				break;
			}
			a--;
		}
	}
	for (int i = 1; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("%d\n", arr[n]);
	return 0;
}