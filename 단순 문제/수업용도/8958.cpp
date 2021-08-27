#include <stdio.h>
#include <string.h>

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		char arr[100]; scanf("%s", arr+1);
		int score[100] = { 0, };
		int l = strlen(arr+1);
		for (int i = 1; i <= l; i++) {
			if (arr[i] == 'O' && arr[i - 1] != 'O') {
				score[i] = 1;
			}
			else if (arr[i] == 'O') {
				score[i] = score[i - 1]+1;
			}
		}
		int ans = 0;
		for (int i = 1; i <= l; i++) {
			ans += score[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}