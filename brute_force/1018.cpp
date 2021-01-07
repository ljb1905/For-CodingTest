#include <stdio.h>
#include <algorithm>
using namespace std;

char arr[51][51];
int n, m;

int Bfun(int y, int x) {
	int ret=0;
	bool flag = true;
	for (int i = y; i < y+8; i++) {
		for (int j = x; j < x+8; j++) {
			if (arr[i][j] == 'W' && flag == true) {
				ret++;
			}
			else if (arr[i][j] == 'B' && flag == false) {
				ret++;
			}
			flag = !flag;
		}
		flag=!flag;
	}
	return ret;
}

int Wfun(int y, int x) {
	int ret = 0;
	bool flag = true;
	for (int i = y; i < y+8; i++) {
		for (int j = x; j < x+8; j++) {
			if (arr[i][j] == 'B' && flag == true) {
				ret++;
			}
			else if (arr[i][j] == 'W' && flag == false) {
				ret++;
			}
			flag = !flag;
		}
		flag = !flag;
	}
	return ret;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}
	int minn = 987654321;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i + 8 <= n && j + 8 <= m) {
				int tmp = min(64 - Bfun(i,j), 64 - Wfun(i, j));
				if (tmp < minn) {
					minn = tmp;
				}
			}
		}
	}
	printf("%d\n", minn);
	return 0;
}