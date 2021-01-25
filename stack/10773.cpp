#include <stdio.h>
#include <stack>
using namespace std;

stack<int> s;

int main() {
	int k; scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int a; scanf("%d", &a);
		if (a == 0) {
			s.pop();
		}
		else {
			s.push(a);
		}
	}
	int ans = 0;
	while (!s.empty()) {
		ans += s.top();
		s.pop();
	}
	printf("%d\n", ans);
	return 0;
}