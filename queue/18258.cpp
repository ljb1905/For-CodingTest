#include <stdio.h>
#include <string.h>

int q[2000001];

int main() {
	int n; scanf("%d", &n);
	int inp = 0;
	int fro = 0;
	for (int i = 0; i < n; i++) {
		char ord[10]; scanf("%s", ord);
		int sz = inp - fro;
		if (strcmp(ord, "push") == 0) {
			int a; scanf("%d", &a);
			q[inp++] = a;
		}
		else if (strcmp(ord, "pop") == 0) {
			if (sz == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q[fro++]);
			}
		}
		else if (strcmp(ord, "size") == 0) {
			printf("%d\n", sz);
		}
		else if (strcmp(ord, "empty") == 0) {
			if (sz == 0)
				printf("1\n");
			else
				printf("0\n");
		}
		else if (strcmp(ord, "front") == 0) {
			if (sz == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q[fro]);
			}
		}
		else if (strcmp(ord, "back") == 0) {
			if (sz == 0) {
				printf("-1\n");
			}
			else {
				printf("%d\n", q[inp-1]);
			}
		}
	}
	return 0;
}