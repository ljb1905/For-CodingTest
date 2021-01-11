#include <stdio.h>
#include <vector>
using namespace std;

bool chk(int n) {
	bool ret = true;
	vector <int> v;
	while (n) {
		int tmp = n % 10;
		n /= 10;
		v.push_back(tmp);
	}
	for (int i = 2; i < v.size(); i++) {
		if (v[i - 2] - v[i - 1] != v[i - 1] - v[i])
			ret = false;
	}
	return ret;
}

int main()
{
	int n; scanf("%d", &n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (chk(i)) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}