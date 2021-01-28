#include <stdio.h>
#include <utility>
using namespace std;

int white, blue;
int arr[130][130];
void chk(int y, int x, int a) {
	int cnt = 0;
	int fi = arr[y][x];
	for (int i = y; i < y + a; i++) {
		for (int j = x; j < x + a; j++) {
			if (fi == arr[i][j])
				cnt++;
		}
	}
	if (cnt == a * a) {
		if (fi == 1)
			blue++;
		else
			white++;
		return;
	}
	chk(y, x, a / 2);
	chk(y + a / 2, x, a / 2);
	chk(y, x + a / 2, a / 2);
	chk(y + a / 2, x + a / 2, a / 2);
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	chk(0, 0, n);
	printf("%d\n%d\n", white, blue);
	return 0;
}