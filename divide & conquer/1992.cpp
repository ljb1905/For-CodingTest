#include <stdio.h>

int arr[65][65];
void func(int y, int x, int n) {
	int cnt = 0;
	int val = arr[y][x];
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (val == arr[i][j]) {
				cnt++;
			}
		}
	}
	if (cnt == n * n) {
		printf("%d", val);
		return;
	}
	printf("(");
	func(y, x, n / 2);
	func(y, x+n/2, n / 2);
	func(y + n / 2, x, n / 2);
	func(y + n / 2, x + n / 2, n / 2);
	printf(")");
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	func(0, 0, n);
	return 0;
}