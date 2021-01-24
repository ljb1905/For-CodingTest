#include <stdio.h>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	pair<int, int> p;
	for (int i = 2; i <= n; i++) {
		int now = i;
		while (1) {
			if (now % 2 != 0 && now % 5 != 0) {
				break;
			}
			else if (now % 2 == 0) {
				now /= 2;
				p.first++;
			}
			else if (now % 5 == 0) {
				now /= 5;
				p.second++;
			}
		}
	}
	printf("%d\n", min(p.first, p.second));
	return 0;
}