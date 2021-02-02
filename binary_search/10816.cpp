#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[500001];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int a; scanf("%d", &a);
		int l = 0;
		int r = n-1;
		int mid = (l + r) / 2;
		while (l <= r) {
			mid = (l + r) / 2;
			int findval = arr[mid];
			if (findval <= a) { //같아도 l을 옮김(lower bound -> a이상의 값 제일 오른쪽)
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		int ans1 = l; 
		l = 0, r = n-1;
		while (l <= r) { // 
			mid = (l + r) / 2;
			int findval = arr[mid];
			if (findval >= a) { //같아도 r을 내림(upper bound -> 몇번째부터 a 초과되는지)
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		int ans = ans1 - l; //둘다 l을 반환
		if (i == m - 1) {
			printf("%d\n", ans);
		}
		else {
			printf("%d ", ans);
		}
	}
	return 0;
}