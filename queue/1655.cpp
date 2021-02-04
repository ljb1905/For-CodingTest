#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

priority_queue <int, vector<int>, greater <int>> minpq; // min heap
priority_queue <int, vector<int>, less<int>> maxpq; // max heap

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		maxpq.push(a);
		if (maxpq.size() - minpq.size() > 1) {
			minpq.push(maxpq.top());
			maxpq.pop();
		}
		if (maxpq.size() > minpq.size() && !minpq.empty() && maxpq.top() > minpq.top()) {
			int tmp = minpq.top();
			minpq.pop();
			int tmp2 = maxpq.top();
			maxpq.pop();
			minpq.push(tmp2);
			maxpq.push(tmp);
		}
		printf("%d\n", maxpq.top());


	}
	return 0;
}