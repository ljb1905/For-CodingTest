#include <stdio.h>
#include <stack>
using namespace std;

int arr[1000001];
int ans[1000001];
stack <int> s;

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && s.top() <= arr[i]) {
			s.pop();
		}
		if (!s.empty() && s.top() > arr[i]) {
			ans[i] = s.top();
		}
		s.push(arr[i]);
		if (ans[i] == 0) {
			ans[i] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}