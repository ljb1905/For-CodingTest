#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

char arr[100001];
stack<char> s;
stack<char> q;

int main() {
	scanf("%s", arr);
	int l = strlen(arr);
	for (int i = 0; i < l; i++) {
		s.push(arr[i]);
	}
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char inp[4]; scanf(" %[^\n]s", inp);
		if (inp[0] == 'P') {
			s.push(inp[2]);
		}
		else if (inp[0] == 'L') {
			if (!s.empty()) {
				q.push(s.top());
				s.pop();
			}
		}
		else if (inp[0] == 'D') {
			if (!q.empty()) {
				s.push(q.top());
				q.pop();
			}
		}
		else if (inp[0] == 'B') {
			if (!s.empty()) {
				s.pop();
			}
		}
	}
	stack<char> ans;
	while (!s.empty()) {
		ans.push(s.top());
		s.pop();
	}
	while (!ans.empty()) {
		printf("%c", ans.top());
		ans.pop();
	}
	while (!q.empty()) {
		printf("%c", q.top());
		q.pop();
	}
	printf("\n");
	return 0;
}