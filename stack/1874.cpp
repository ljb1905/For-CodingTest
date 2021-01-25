#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

stack <int> s;
queue <char> q;

int main() {
	int n; scanf("%d", &n);
	int now = 1;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (s.empty() || s.top() < a) {
			while (a >= now) {
				s.push(now++);
				q.push('+');
			}
			
		}
		if (!s.empty() && s.top() == a) {
			s.pop();
			q.push('-');
		}
	}
	if (q.size() == 2*n) {
		while (!q.empty()) {
			printf("%c\n", q.front());
			q.pop();
		}
	}
	else {
		printf("NO\n");
	}
	return 0;
}