#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10];
bool chk[10];
bool anschk = false;

void dfs(int cnt, int idx,int sum) {
	if (idx == 9) {
		if (cnt == 7 && sum == 100) {
			anschk = true;
		}
		return;
	}
	if (anschk) return;
	chk[idx] = true;
	dfs(cnt + 1, idx + 1, sum + arr[idx]);
	if (anschk) return;
	chk[idx] = false;
	dfs(cnt, idx + 1, sum);	
	if (anschk) return;
}

int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr[i]);
	}
	dfs(0, 0, 0);
	vector<int> ans;
	for (int i = 0; i < 9; i++) {
		if (chk[i]) ans.push_back(arr[i]);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}