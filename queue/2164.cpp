#include <stdio.h>
#include <queue>
using namespace std;

queue <int>  q;
int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	bool sw = true;
	while (q.size() != 1) {
		if (sw) {
			q.pop();
		}
		else {
			q.push(q.front());
			q.pop();
		}
		sw = !sw;
	}
	printf("%d\n", q.front());
}
