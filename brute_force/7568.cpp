#include <stdio.h>

struct x {
	int a, b;
}arr[51];
int cnt[51];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].a, &arr[i].b);
	}
	for (int i = 0; i < n; i++) {
		cnt[i]++;
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (arr[i].a < arr[j].a && arr[i].b < arr[j].b) {
				cnt[i]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", cnt[i]);
	}
	return 0;
}