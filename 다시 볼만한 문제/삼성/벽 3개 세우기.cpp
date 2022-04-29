//백준 14502

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int arr[10][10];
int n, m;
int wallcnt=3;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
vector<pair<int, int>> emp;
vector<pair<int, int>> vir;
int ans;

void func() {
	int cnt = vir.size();
	queue<pair<int, int>> q;
	bool chk[10][10] = { 0, };
	for (int i = 0; i < vir.size(); i++) {
		q.push(make_pair(vir[i].first, vir[i].second));
		chk[vir[i].first][vir[i].second] = true;
	}
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nexty = now.first + dy[i];
			int nextx = now.second + dx[i];
			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m) continue;
			if (chk[nexty][nextx]) continue;
			if (arr[nexty][nextx] == 1) continue;
			chk[nexty][nextx] = true;
			q.push(make_pair(nexty, nextx));
			cnt++;
		}
	}
	int tmp = cnt + wallcnt;
	ans = max(ans, n*m-tmp);
	return;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 0) {
				emp.push_back(make_pair(i, j));
			}
			else if (arr[i][j] == 2) {
				vir.push_back(make_pair(i, j));
			}
			else wallcnt++;
		}
	}
	for (int x = 0; x < emp.size(); x++) {
		for (int y = x + 1; y < emp.size(); y++) {
			for (int z = y + 1; z < emp.size(); z++) {
				arr[emp[x].first][emp[x].second] = 1;
				arr[emp[y].first][emp[y].second] = 1;
				arr[emp[z].first][emp[z].second] = 1;
				func();
				arr[emp[x].first][emp[x].second] = 0;
				arr[emp[y].first][emp[y].second] = 0;
				arr[emp[z].first][emp[z].second] = 0;
			}
		}
	}
	printf("%d\n", ans);
	
	return 0;
}