#include <stdio.h>
#include <string.h>

int main()
{
	char arr[101]; scanf("%s", arr);
	int l = strlen(arr);
	int pos[27];
	for (int i = 0; i < 26; i++) {
		pos[i] = -1;
	}
	for (int i = 0; i < l; i++) {
		if (pos[arr[i]-'a'] != -1) continue;
		pos[arr[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", pos[i]);
	}
	return 0;
}