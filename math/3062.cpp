#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

char arr[10];
char brr[10];

void func(char *inp) {
	int l = strlen(inp);
	for (int i = 0; i < l; i++) {
		brr[i] = arr[l - i - 1];
	}
	return;
}
int val(char* inp) {
	int ret = 0;
	int n = 1;
	int l = strlen(inp);
	for (int i = l - 1; i >= 0; i--) {
		ret += (inp[i] - '0') * n;
		n *= 10;
	}
	return ret;
}
bool chk(int now) {
	vector<char> v;
	while (now) {
		v.push_back((now % 10) + '0');
		now /= 10;
	}
	bool ret = true;
	for (int i = 0; i < v.size() / 2; i++) {
		if (v[i] != v[v.size() - i - 1]) {
			ret = false;
			break;
		}
	}
	return ret;
}

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		scanf("%s", arr);
		for (int i = 0; i < 10; i++) brr[i] = 0;
		func(arr);
		int now = val(arr) + val(brr);
		if (chk(now)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}