#include <stdio.h>
#include <string.h>

int main() {
	while (1) {
		char arr[501]; scanf(" %[^\n]s", arr);
		if (strcmp(arr, "END")==0) break;
		int l = strlen(arr);
		for (int i = l - 1; i >= 0; i--) printf("%c", arr[i]);
		printf("\n");
	}
	return 0;
}