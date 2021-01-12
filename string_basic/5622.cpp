#include <stdio.h>
#include <string.h>

int val[27] = { 1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };

int main()
{
	char arr[16]; scanf("%s", arr);
	int l = strlen(arr);
	int ans = 0;
	for (int i = 0; i < l; i++) {
		ans += val[arr[i] - 'A' + 1];
	}
	printf("%d\n", ans + l);

	return 0;
}