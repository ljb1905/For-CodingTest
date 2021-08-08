#include <stdio.h>
#include <vector>
using namespace std;

int main() {
	while (1) {
		int a; scanf("%d", &a);
		if (a == -1) break;
		int sum = 0;
		vector<int> v;
		for (int i = 1; i <= a / 2; i++) {
			if (a % i == 0) {
				sum += i;
				v.push_back(i);
			}
		}
		if (sum == a) {
			printf("%d = ", a);
			for (int i = 0; i < v.size() - 1; i++) {
				printf("%d + ", v[i]);
			}
			printf("%d\n", v[v.size() - 1]);
		}
		else {
			printf("%d is NOT perfect.\n", a);
		}
	}
	return 0;
}