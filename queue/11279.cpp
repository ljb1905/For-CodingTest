#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

priority_queue <int> pq;

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (a == 0 && pq.size() == 0) {
			printf("0\n");
		}
		else if (a == 0) {
			printf("%d\n", pq.top());
			pq.pop();
		}
		else {
			pq.push(a);
		}
	}
	return 0;
}