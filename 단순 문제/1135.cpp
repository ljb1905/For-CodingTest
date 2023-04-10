#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[51];

int dfs(int now) {
	int ret = 0;
	vector<int> nextt;
	int w = v[now].size() - 1;
	for (int i = 0; i < v[now].size(); i++) {
		nextt.push_back(dfs(v[now][i]));
	}
	sort(nextt.begin(), nextt.end());
	for (int i = 0; i < nextt.size(); i++) {
		ret = max(ret, nextt[i] + w--);
	}
	return ret + 1;

}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp; scanf("%d", &tmp);
		if (tmp == -1) continue;
		v[tmp].push_back(i);
	}
	int ans = dfs(0);
	printf("%d\n", ans - 1);
	return 0;
}