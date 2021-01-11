#include <stdio.h>
#include <ctype.h>
#include <string.h>

char arr[1000001];

int main()
{
	//gets_s(arr);
	scanf("%[^\n]", arr);
	int ans = 0;
	int l = strlen(arr);
	for (int i = 0; i < l; i++) {
		if (arr[i] != ' ') {
			if (i != 0 && arr[i - 1] != ' ')
				continue;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}