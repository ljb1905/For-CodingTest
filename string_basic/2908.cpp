#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

int rev(int n) {
	stack<int> s;
	while (n) {
		int tmp = n % 10;
		n /= 10;
		s.push(tmp);
	}
	int now = 1;
	int ret = 0;
	while(!s.empty()) {
		ret += now * s.top();
		s.pop();
		now *= 10;
	}
	return ret;
}

int main()
{
	int a, b; scanf("%d %d", &a, &b);
	printf("%d\n", max(rev(a), rev(b)));
	return 0;
}