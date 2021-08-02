#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

char arr[10];
bool chk[1000001][11];
int k,l;

struct s {
	int now, dep;
	s(){}
	s(int now, int dep):
		now(now), dep(dep)
	{}
};
queue <s> q;
int pow(int n) {
	int ret = 1;
	for (int i = 0; i < n; i++) {
		ret *= 10;
	}
	return ret;
}
int trans() {
	int ret = 0;
	int n = 1;
	for (int i = l-1; i >= 0; i--) {
		ret += n * (arr[i]-'0');
		n *= 10;
	}
	return ret;
}
int func(int now, int i, int j) {
	int ival = ((now % (pow(i) * 10)) / pow(i));
	int jval = ((now % (pow(j) * 10)) / pow(j));
	now -= ival* pow(i);
	now += jval * pow(i);
	now -= jval * pow(j);
	now += ival * pow(j);
	return now;
}

int main() {
	scanf("%s %d", arr, &k);
	for (int i = 0; arr[i] != 0; i++) {
		l++;
	}
	int chkcnt = 0;
	for (int i = 0; i < l; i++) {
		if (arr[i] != '0') chkcnt++;
	}
	if (l <= 2 && chkcnt == 1) {
		printf("-1\n");
		return 0;
	}
	int maxx = 0;
	q.push(s(func(trans(),1,1),0));
	while (!q.empty()) {
		int nowval = func(q.front().now,1,1);
		int nowdep = q.front().dep;
		q.pop();
		if (nowdep == k) {
			if (maxx < nowval) maxx = nowval;
			continue;
		}
		if (chk[nowval][nowdep]) {
			continue;
		}
		chk[nowval][nowdep] = true;
		for (int i = 0; i < l; i++) {
			for (int j = i + 1; j < l; j++) {
				q.push(s(func(nowval,i,j), nowdep + 1));
			}
		}
	}
	printf("%d\n", maxx);
	return 0;
}