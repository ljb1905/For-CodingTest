#include <stdio.h>

int const maxx = 10001;
int cnt[maxx];

int main() {
	int n; scanf("%d\n", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cnt[a]++;
	}
	for (int i = 1; i < maxx; i++) {
		if (cnt[i] > 0) {
			cnt[i]--;
			printf("%d\n", i);
			i--;
		}
	}
	return 0;
}