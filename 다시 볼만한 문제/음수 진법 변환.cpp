#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

int modd(int a, int b) {
	if (a % abs(b) < 0) return (abs(b) + a % abs(b));
	else return (a % abs(b));
}

void func(int n, int m) {
	stack<int> s;
	while (n) {
		int val = modd(n, m);
		s.push(val);
		n -= val;
		n /= m;
	}
	while (!s.empty()) {
		printf("%d", s.top());
		s.pop();
	}
	printf("\n");
	return;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	bool flag = (n < 0 && m > 0) ? true : false;
	if (flag) {
		n = abs(n);
		printf("-");
	}
	if (n == 0) printf("0\n");
	func(n, m);
	return 0;
}