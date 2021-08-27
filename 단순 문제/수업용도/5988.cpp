#include <stdio.h>
#include <string.h>

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char arr[100]; scanf("%s", arr);
		int l = strlen(arr);
		int val = arr[l - 1] - '0';
		if (val % 2 == 1) {
			printf("odd\n");
		}
		else
			printf("even\n");
	}
	return 0;
}