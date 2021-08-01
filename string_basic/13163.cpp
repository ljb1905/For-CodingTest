#include <stdio.h>
#include <string.h>

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		char arr[101]; scanf(" %[^\n]s", arr);
		int l = strlen(arr);
		bool chk = false;
		for(int i = 0; i < l; i++) {
			if (arr[i] == ' ')
			{
				if (chk == false) {
					printf("god");
				}
				chk = true;
			}
			else if (chk == false) continue;
			else {
				printf("%c", arr[i]);
			}
		}
		printf("\n");
	}
	return 0;
}