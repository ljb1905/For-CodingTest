#include <stdio.h>
#include <string.h>

int cnt[30];

int main() {
	char arr[1000001]; scanf("%s", arr);
	int l = strlen(arr);
	/*int l = 0;
	for (int i = 0;; i++) {
		if (arr[i] == 0) {
			l = i;
			break;
		}
	}*/
	for (int i = 0; i < l; i++) {
		if (arr[i] <= 'Z' && arr[i] >= 'A') {
			cnt[arr[i] - 'A']++;
		}
		else {
			cnt[arr[i] - 'a']++;
		}
	}
	int maxx = -1;
	bool flag = false;
	int ans = 0;
	for (int i = 0; i <= 26; i++) {
		if (maxx == cnt[i]) {
			flag = true;
		}
		else if (maxx < cnt[i]) {
			flag = false;
			maxx = cnt[i];
			ans = i;
		}
	}
	if (flag)
		printf("?\n");
	else
		printf("%c", ans + 'A');
	return 0;
}