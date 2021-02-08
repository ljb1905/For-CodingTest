#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <vector>

using namespace std;
const int inp = 1000001;

vector <int> v;
int arr[inp];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	v.push_back(INT_MIN);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > v.back()) {
			ans++;
			v.push_back(arr[i]);
		}
		else {
			auto tmp = lower_bound(v.begin(), v.end(), arr[i]);
			*tmp = arr[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}