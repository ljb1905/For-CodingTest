#include <stdio.h>
#include <string.h>

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		int n;
		char arr[21];
		scanf("%d %s", &n, arr);
		int l = strlen(arr);
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < n; j++) {
				printf("%c", arr[i]);
			}
		}
		printf("\n");
	}
	return 0;
}