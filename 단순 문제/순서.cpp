//백준 1375 

#include <stdio.h>
#include <vector>
#include <map>
#include <string>
using namespace std;

vector<int> v[1000001];
map<int, int> chk;

bool dfs(int now, int endd) {
	if (now == endd) {
		return true;
	}
	if (chk[now]) return false;
	chk[now]++;
	bool ret = false;
	for (int i = 0; i < v[now].size(); i++) {
		if (chk[v[now][i]]) continue;
		ret = dfs(v[now][i], endd);
		if (ret) return ret;
	}
	return ret;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	map<string, int> mapp;
	int cnt = 1;
	for (int i = 0; i < m; i++) {
		char arr[10];
		char brr[10];
		scanf("%s %s", arr, brr);
		if (!mapp[arr]) mapp[arr] = cnt++;
		if (!mapp[brr]) mapp[brr] = cnt++;
		v[mapp[brr]].push_back(mapp[arr]);
	}
	int k; scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		char arr[10];
		char brr[10];
		scanf("%s %s", arr, brr);
		if (mapp[arr] == mapp[brr] || !mapp[arr] || !mapp[brr]) {
			printf("gg\n");
			continue;
		}
		chk.clear();
		if (dfs(mapp[arr], mapp[brr])) {
			printf("%s ", brr);
			continue;
		}
		chk.clear();
		if (dfs(mapp[brr], mapp[arr])) {
			printf("%s ", arr);
			continue;
		}			
		printf("gg ");
	}
	printf("\n");
	return 0;
}