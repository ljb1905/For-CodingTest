#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
using namespace std;

char arr[51];
queue <char> q;
queue <int> pos;

int ans = 0;

int main()
{
	scanf("%s", arr);
	int l = strlen(arr);
	int fstm = 55;
	for (int i = 0; i < l; i++) {
		if (arr[i] == '-' || arr[i] == '+') {
			if (arr[i] == '-' && fstm == 55)
				fstm = i;
			q.push(arr[i]);
			pos.push(i);
		}
	}
	pos.push(0);
	int idx = 0;
	int pro = 1;
	while (!pos.empty()) {
		if (idx > fstm) {
			pro = -1;
		}
		int nowval = atoi(arr + idx);
		ans += nowval*pro;
		idx = pos.front() + 1;
		pos.pop();
	}
	printf("%d\n", ans);
	return 0;
}