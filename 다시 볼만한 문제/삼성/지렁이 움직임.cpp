//백준 3190 뱀

#include <stdio.h>
#include <queue>
using namespace std;

bool app[101][101];
bool schk[101][101];
int arr[101];
char arr2[101];
queue<int> qy;
queue<int> qx;

int main() {
	int n; scanf("%d", &n);
	int k; scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a, b; scanf("%d %d", &a, &b);
		app[a-1][b-1] = true;
	}
	int l; scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d %c", &arr[i], &arr2[i]);
	}
	int dir = 3; //위 왼 아 오
	int heady = 0;
	int headx = 0;
	int taily = 0;
	int tailx = 0;
	int dy = 0;
	int dx = 0;
	int ans = 0;
	schk[0][0] = true;
	int nowidx = 0;
	int sz = 1;
	while (1) {
		ans++;
		if (dir == 0) {
			dy = -1;
			dx = 0;
		}
		else if (dir == 1) {
			dy = 0;
			dx = -1;
		}
		else if (dir == 2) {
			dy = 1;
			dx = 0;
		}
		else {
			dy = 0;
			dx = 1;
		}

		// 머리 먼저
		heady += dy;
		headx += dx;
		qy.push(heady);
		qx.push(headx);
		if (heady >= n || headx >= n || heady < 0 || headx < 0) break;
		if (schk[heady][headx]) break;
		schk[heady][headx] = true;
		if (app[heady][headx]) {
			app[heady][headx] = false;
			sz++;
		}
		else {
			schk[taily][tailx] = false;
			if (sz <= qy.size()) {
				taily = qy.front();
				tailx = qx.front();
				qy.pop();
				qx.pop();
			}
		}
		if (nowidx < l && arr[nowidx] == ans) {
			if (arr2[nowidx] == 'L') dir++;
			else if (arr2[nowidx] == 'D') dir--;
			if (dir == 4) dir = 0;
			if (dir == -1) dir = 3;
			nowidx++;
		}

		///
		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (taily == i && tailx == j) printf("2 ");
				else if (heady == i && headx == j) printf("3 ");
				else printf("%d ", schk[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");*/
	}
	printf("%d\n", ans);
	return 0;
}