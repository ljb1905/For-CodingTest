#include <stdio.h>

int arr[55];
int val[55];
bool chk[55];

int min(int a, int b) { return a < b ? a : b; }

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		val[i] = i + 1;
	}
	int st = 0;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		int findval = arr[i];
		bool flag = false;
		int step[2] = { 0, };
		for (int j = st; j < n + st; j++) {
			int idx = j % n;
			if (findval == val[idx]) {
				break;
			}
			if(chk[idx]==false)
				step[0]++;
		}
		for (int j = n+st; j > st ; j--) {
			int idx = j % n;
			if (j == n && flag == false)
				continue;
			if (findval == val[idx]) {
				step[1]++;
				break;
			}
			if (chk[idx] == false)
				step[1]++;
			flag = true;
		}
		chk[findval-1] = true;
		st = findval - 1;
		ans += min(step[0], step[1]);
	}
	printf("%d\n", ans);
	return 0;
}