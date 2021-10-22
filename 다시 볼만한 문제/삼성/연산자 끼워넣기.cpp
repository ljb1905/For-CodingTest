#include <stdio.h>
#include <algorithm>
#include <limits.h>
using namespace std;

int arr[15];
char ope[15];
int cnt[4];
int n;
int maxx = INT_MIN;
int minn = INT_MAX;

void dfs(int val) {
	if (val == n - 1) {
		int tmp=arr[0];
		for (int i = 1; i < n; i++) {
			if (ope[i - 1] == '+')
				tmp += arr[i];
			else if (ope[i - 1] == '-')
				tmp -= arr[i];
			else if (ope[i - 1] == '*')
				tmp *= arr[i];
			else
				tmp /= arr[i];
		}
		maxx = max(maxx, tmp);
		minn = min(minn, tmp);
		return;
	}
	if (cnt[0]) {
		cnt[0]--;
		ope[val] = '+';
		dfs(val + 1);
		cnt[0]++;
	}
	if (cnt[1]) {
		cnt[1]--;
		ope[val] = '-';
		dfs(val + 1);
		cnt[1]++;
	}
	if (cnt[2]) {
		cnt[2]--;
		ope[val] = '*';
		dfs(val + 1);
		cnt[2]++;
	}
	if (cnt[3]) {
		cnt[3]--;
		ope[val] = '/';
		dfs(val + 1);
		cnt[3]++;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &cnt[i]);
	}
	dfs(0);
	printf("%d\n%d", maxx, minn);
	return 0;
}