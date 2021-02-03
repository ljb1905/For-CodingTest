#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[200001];
int dis[200001];
int maxx;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		maxx = max(maxx, arr[i]);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++){
		dis[i] = arr[i + 1] - arr[i];
	}
	int l = 1;
	int r = maxx;
	int mid = (l + r) / 2;
	int ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		int cnt = 1;
		int val = 0;
		for (int i = 0; i < n-1; i++) {
			if (dis[i]+val >= mid) {
				cnt++;
				val = 0;
			}
			else {
				val += dis[i];
			}
		}
		if (cnt < m) { //개수가 더 적으면
			r = mid - 1;
		}
		else {
			ans = mid;
			l = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}