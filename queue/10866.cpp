#include <stdio.h>
#include <deque>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	deque <int> dq;
	for (int i = 0; i < n; i++) {
		char inp[15]; scanf("%s", inp);
		if (strcmp(inp, "push_back") == 0) {
			int a; scanf("%d", &a);
			dq.push_back(a);
		}
		else if (strcmp(inp, "push_front") == 0) {
			int a; scanf("%d", &a);
			dq.push_front(a);
		}
		else if (strcmp(inp, "pop_front") == 0) {
			if (dq.empty())
				printf("-1\n");
			else {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if (strcmp(inp, "pop_back") == 0) {
			if (dq.empty())
				printf("-1\n");
			else {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		}
		else if (strcmp(inp, "size") == 0) {
			printf("%d\n", dq.size());
		}
		else if (strcmp(inp, "empty") == 0) {
			printf("%d\n", dq.empty());
		}
		else if (strcmp(inp, "front") == 0) {
			if (dq.empty())
				printf("-1\n");
			else
				printf("%d\n", dq.front());
		}
		else if (strcmp(inp, "back") == 0) {
			if (dq.empty())
				printf("-1\n");
			else
				printf("%d\n", dq.back());
		}
	}
	return 0;
}