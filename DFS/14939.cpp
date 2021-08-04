#include <stdio.h>
#include <algorithm>
using namespace std;

char ori[11][11];
char now[11][11];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,1,-1 };
bool chk[11];
int ans = 987654321;
char sw(char a) {
	if (a == 'O') return '#';
	return 'O';
}

void func(int idx) {
	if (idx == 11) {
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				now[i][j] = ori[i][j];
			}
		}
		int cnt = 0;
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				if (i == 1) {
					if (chk[j]) {
						cnt++;
						for (int k = 0; k < 5; k++) {
							int nowj = j + dx[k];
							int nowi = i + dy[k];
							if (nowj <= 0 || nowj >= 11 || nowi <= 0 || nowi >= 11) continue;
							else now[nowi][nowj] = sw(now[nowi][nowj]);
						}
					}
				}
				else {
					if (now[i - 1][j] == 'O') {
						cnt++;
						for (int k = 0; k < 5; k++) {
							int nowj = j + dx[k];
							int nowi = i + dy[k];
							if (nowj <= 0 || nowj >= 11 || nowi <= 0 || nowi >= 11) continue;
							else now[nowi][nowj] = sw(now[nowi][nowj]);
						}
					}
				}
			}
		}
		bool flag = false;
		for (int i = 1; i <= 10; i++) {
			for (int j = 1; j <= 10; j++) {
				if (now[i][j] == 'O') {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (!flag) ans = min(ans, cnt);
		return;
	}
	chk[idx] = true;
	func(idx + 1);
	chk[idx] = false;
	func(idx + 1);
}

int main() {
	for (int i = 1; i <= 10; i++) {
		scanf("%s", ori[i]+1);
	}
	func(1);
	if (ans == 987654321) ans = -1;
	printf("%d\n", ans);
	return 0;
}