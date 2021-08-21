#include <stdio.h>
#include <algorithm>
using namespace std;

struct strr {
	int st, ed;
	strr(){}
	strr(int st,int ed):
		st(st),ed(ed)
	{}
	bool operator < (const strr & o)const {
		if (ed == o.ed) return st < o.st;
		return ed < o.ed;
	}
}arr[100001];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i].st, &arr[i].ed);
	}
	sort(arr + 1, arr + 1 + n);
	int now = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (now <= arr[i].st) {
			ans++;
			now = arr[i].ed;
		}
	}
	printf("%d\n", ans);
	return 0;
}