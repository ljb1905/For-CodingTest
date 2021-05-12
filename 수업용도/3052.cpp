#include <stdio.h>

bool chk[45];

int main() {
	for (int i = 1; i <= 10; i++) {
		int n; scanf("%d", &n);
		chk[n % 42] = true;
	}
	int ans = 0;
	int idx = 0;
	while (ans < 10 && idx<42) {
		if (chk[idx])
			ans++;
		idx++;
	}
	printf("%d\n", ans);
	return 0;
}