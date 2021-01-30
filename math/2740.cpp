#include <stdio.h>

int arr[3][101][101];

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[0][i][j]);
		}
	}
	int y, x; scanf("%d %d", &y, &x);
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			scanf("%d", &arr[1][i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < x; j++) {
			int sum = 0;
			for (int k = 0; k < m; k++) {
				sum += arr[0][i][k] * arr[1][k][j];
			}
			arr[2][i][j] = sum;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < x-1; j++) {
			printf("%d ", arr[2][i][j]);
		}
		printf("%d\n",arr[2][i][x-1]);
	}
	return 0;
}