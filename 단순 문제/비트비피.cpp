//백준 1102

#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[17][17];
int ans = 987654321;
int n;
int ori;
int endp;
int chk[1<<17];
char inp[17];

void dfs(int stat, int sum) {
	int tmp = 0;
	if (chk[stat] <= sum) return;
	chk[stat] = sum;
	for (int i = 0; i < n; i++) {
		if (stat & (1 << i)) tmp++;
	}
	if (tmp >= endp) {
		if (sum < ans) ans = sum;
		return; 
	}
	for (int st = 0; st < n; st++) {
		for (int ed = 0; ed < n; ed++) {
			if (st == ed) continue;
			if (stat & (1 << st)) {
				if (stat & (1 << ed)) continue;
				dfs(stat | (1 << ed), sum + arr[st][ed]);
			}
		}
	}
	return;
}

int main() {
	scanf("%d", &n);
	int ee = (1 << n) - 1;
	for (int i = 0; i <= ee; i++) {
		chk[i] = 987654321;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	scanf("%s", inp);
	int l = strlen(inp);
	for (int i = l-1; i >=0 ; i--) {
		if (inp[i] == 'Y') ori += (1 << i);
	}
	scanf("%d", &endp);
	dfs(ori, 0);
	if (ans == 987654321) ans = -1;
	printf("%d\n", ans);
	return 0;
}