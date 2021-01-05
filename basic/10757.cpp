#include <stdio.h>
#include <string.h>

char arr[10011];
char brr[10011];
char tmp[10011];
char sum[10011];

int main()
{
	scanf("%s %s", arr,brr);
	int l1 = strlen(arr);
	int l2 = strlen(brr);
	if (l2 > l1) {
		strcpy(tmp, arr);
		strcpy(arr, brr);
		strcpy(brr, tmp);
		int tmp = l1;
		l1 = l2;
		l2 = tmp;
	}
	for (int i = l2 - 1; i >= 0; i--) {
		brr[i + l1 - l2] = brr[i];
	}
	for (int i = 0; i < l1-l2; i++) {
		brr[i] = 0;
	}
	bool chk = false;
	for (int i = l1 - 1; i >= 0; i--) {
		if (brr[i] == 0)
			sum[i] = arr[i];
		else
			sum[i] = arr[i] + brr[i] - '0';
		if (sum[i] > '9') {
			sum[i] -= 10;
			if (i == 0) {
				chk = true;
				break;
			}
			arr[i - 1] ++;
		}			
	}
	if (chk)
		printf("1""%s\n", sum);
	else
		printf("%s\n", sum);

	return 0;
}