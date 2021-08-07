#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
bool notPrime[1000011];

int main() {
	for (int i = 2; i < sqrt(1000001); i++) {
		if (notPrime[i]) continue;
		for (int j = 2 * i; j < 1000001; j+=i) {
			notPrime[j] = true;
		}
	}
	for (int i = 3; i < 1000000; i++) {
		if (!notPrime[i]) v.push_back(i);
	}
	while (1) {
		int a; scanf("%d", &a);
		if (a == 0) break;
		int ans1, ans2;
		for (int i = 0; i < v.size(); i++) {
			int now = v[i];
			if (!notPrime[a - now]) {
				ans1 = max(a-now, now);
				ans2 = min(a - now, now);
				break;
			}
		}
		printf("%d = %d + %d\n", a, ans2, ans1);
	}
	return 0;
}