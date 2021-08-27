#include <stdio.h>
#include <string.h>

void func(char arr[][10], int l) {
	for (int i = 0; i < l; i++) {
		if (arr[0][i] == '5') { //
			arr[1][i] = '5';
			arr[2][i] = '6';
		}
		else if (arr[0][i] == '6') {
			arr[1][i] = '5';
			arr[2][i] = '6';
		}
		else {
			arr[1][i] = arr[0][i];
			arr[2][i] = arr[0][i];
		}
	}
	return;
}
int val(char arr[], int l) {
	int ret = 0;
	int tmp = 1;
	for (int i = l - 1; i >= 0; i--) {
		ret += (arr[i] - '0')* tmp;
		tmp *= 10;
	}
	return ret;
}

int main() {
	char arr[3][10]; //0번은 original 1번은 최소, 2번은 최대
	char brr[3][10];
	scanf("%s %s", arr[0], brr[0]);
	int la = strlen(arr[0]); //4
	int lb = strlen(brr[0]); //4
	func(arr, la);
	func(brr, lb);
	int ans1 = val(arr[1], la) + val(brr[1], lb);
	int ans2 = val(arr[2], la) + val(brr[2], lb);
	printf("%d %d\n", ans1, ans2);
	return 0;
}