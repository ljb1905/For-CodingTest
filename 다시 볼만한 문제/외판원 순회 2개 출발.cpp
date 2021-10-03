#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int adj[21][21];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	int S1, S2; scanf("%d %d", &S1, &S2);
	int last = (1 << n) - 1;
	int chk = (1 << (S1 - 1)) | (1 << (S2 - 1));
	vector<vector<int>> d(n, vector<int>(last + 1, 987654321));
	d[S1][1 << S1] = d[S2][1 << S2] = 0;
	for (int stat = 0; stat <= last; stat++) {
		if (!(stat & chk)) continue;
		vector<int> now, next;
		for (int i = 0; i < n; i++) {
			if (stat & (1 << i)) now.push_back(i);
			else next.push_back(i);
		}
		for (int a = 0; a < now.size(); a++) {
			for (int b = 0; b < next.size(); b++) {
				int i = now[a];
				int j = next[b];
				d[j][stat | (1 << j)] = min(d[j][stat | (1 << j)], d[i][stat] + adj[i][j]);
			}
		}
	}
	int ans = 987654321;
	for (int i = 0; i < n; i++)
		ans = min(ans, d[i][last]);
	printf("%d\n", ans);
	return 0;
}