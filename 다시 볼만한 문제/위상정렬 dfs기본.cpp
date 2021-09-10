#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

vector<int> v[32001];
stack<int> s;
bool chk[32001];

void dfs(int now) {
	if (chk[now] == true) return;
	chk[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		int nexx = v[now][i];
		if (chk[nexx] == false) 
			dfs(nexx);
	}
	s.push(now);
	return;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		v[a].push_back(b);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
	}
	while (s.size()>1) {
		printf("%d ", s.top());
		s.pop();
	}
	if (!s.empty()) {
		printf("%d\n", s.top());
	}
	return 0;
}