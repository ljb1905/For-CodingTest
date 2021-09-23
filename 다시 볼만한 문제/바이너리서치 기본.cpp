#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[2][100001];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[0][i]);
	}
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr[1][i]);
	}
	sort(arr[0], arr[0] + n);
	for (int i = 0; i < m; i++) {
		bool ans = false;
		int l = 0;
		int r = n-1;
		int mid = (l + r) / 2;
		while (l <= r) {
			mid = (l + r) / 2;
			int findval = arr[1][i];
			int now = arr[0][mid];
			//
			//printf("\n%d %d\n", findval, now);
			//
			if (findval == now) {
				ans = true;
				break;
			}
			else if (findval > now) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		if (ans == true) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}
	return 0;
}