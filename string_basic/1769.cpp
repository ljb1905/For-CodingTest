#include <stdio.h>
#include <string.h>

int func(int n) {
	int ret = 0;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

char arr[1000001];

int main() { 
	scanf("%s", arr);
	int l = strlen(arr);
	int n=0;
	int cnt = 0;
	bool ans = false;
	if (l == 1) n = arr[0] - '0';
	else {
		for (int i = l-1; i >= 0; i--) {
			n += arr[i] - '0';
		}
		cnt++;
	}
	while (1) {
		if (n / 10 == 0) {
			if (n % 3 == 0) {
				ans = true;
			}
			else
				ans = false;
			break;
		}
		n = func(n);
		cnt++;
	}
	printf("%d\n", cnt);
	if (ans) printf("YES\n");
	else printf("NO\n");
	return 0;
}