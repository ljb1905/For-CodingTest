#include <stdio.h>
#include <stack>
using namespace std;

int main() {
	int n, b; scanf("%d %d", &n, &b);
	stack <char> s;
	while (n) {
		int tmp = n % b;
		if (tmp >= 0 && tmp <= 9) {
			s.push(tmp + '0');
		}
		else {
			s.push(tmp + 'A' - 10);
		}
		n /= b;
	}
	while (!s.empty()) {
		printf("%c", s.top());
		s.pop();
	}
	printf("\n");
	return 0;
}