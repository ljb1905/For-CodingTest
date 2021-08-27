#include <stdio.h>

int cal_len(char* arr) {
	int ret = 0;
	while (arr[ret] != 0) {
		ret++;
	}
	return ret;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n;
		char arr[21];
		scanf("%d %s", &n, arr);
		int l = cal_len(arr);
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < n; j++) {
				printf("%c", arr[i]);
			}
		}
		printf("\n");
	}
	return 0;
}