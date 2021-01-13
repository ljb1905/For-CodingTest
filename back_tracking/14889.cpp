#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[21][21];
int n;
int ans = 987654321;
bool chk[21];

void dfs(int cnt, int idx) {
	if (idx == n + 1)
		return;
	if (cnt == n / 2) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (chk[i]) {
				for (int j = 1; j <= n; j++) {
					if (chk[j]) {
						sum += arr[i][j];
					}
				}
			}
		}
		int sum2 = 0;
		for (int i = 1; i <= n; i++) {
			if (!chk[i]) {
				for (int j = 1; j <= n; j++) {
					if (!chk[j]) {
						sum2 += arr[i][j];
					}
				}
			}
		}
		int tmp = abs(sum2 - sum);
		ans = min(tmp, ans);
			
		return;
	}
	chk[idx+1] = true;
	dfs(cnt + 1, idx+1);
	chk[idx+1] = false;
	dfs(cnt, idx+1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs(0,0);
	printf("%d\n", ans);
	return 0;
}