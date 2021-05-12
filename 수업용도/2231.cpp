#include <stdio.h>

int func(int n) {
	int ret = n;
	while (n) {
		int tmp = n % 10;
		ret += tmp;
		n /= 10;
	}
	return ret;
}

int main() {
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i=1;i<=n;i++){
		int tmp = func(i);
		if (tmp == n) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}