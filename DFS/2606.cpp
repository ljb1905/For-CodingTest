#include <stdio.h>
#include <vector>
using namespace std;

vector <int> v[101];
bool chk[101];
int ans;

void func(int now) {
	chk[now] = true;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (chk[next])
			continue;
		chk[next] = true;
		func(next);
		ans++;
	}
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b; scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	func(1);
	printf("%d\n", ans);
	return 0;
}