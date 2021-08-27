#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int main() {
	char arr[1000001];
	scanf("%s", arr);
	int l = strlen(arr);
	int mod = l % 3;
	//mod가 1일 때는 3개씩 잘랐을 때 한개 남음(0이 2개 필요)
	//mod가 2일 때는 3개씩 잘랐을 때 두개 남음(0이 1개 필요)
	//mod가 0일 때는 필요없음
	for (int i = 0; i < l/2; i++) {
		swap(arr[i], arr[l - i - 1]);
	}
	if (mod == 1) {
		arr[l] = '0';
		arr[l + 1] = '0';
		l = l + 2;
	}
	else if (mod == 2) {
		arr[l] = '0';
		l = l + 1;
	}
	for (int i = 0; i < l / 2; i++) {
		swap(arr[i], arr[l - i - 1]);
	}
	int val = 0;
	for (int i = 0; i < l; i++) {
		if (i != 0 && i % 3 == 0) printf("%d", val); //출력
		if (i % 3 == 0) val = 0;
		if (arr[i] == '1') {
			if (i % 3 == 0)
				val += 4;
			else if (i % 3 == 1)
				val += 2;
			else
				val += 1;
		}
	}
	printf("%d\n", val);
	return 0;
}