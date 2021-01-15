#include <stdio.h>
#include <utility>
#include <queue>
using namespace std;

queue<pair<int,int>> q;
bool chk[1000001];

int main()
{
	int n; scanf("%d", &n);
	q.push({ n,0 });
	int ans = 0;
	while (1) {
		n = q.front().first;
		int step = q.front().second;
		q.pop();
		chk[n] = true;
		if (n == 1) {
			ans = step;
			break;
		}
		if (n % 3 == 0) {
			if (chk[n / 3] == false) {
				chk[n / 3] = true;
				q.push({ n / 3,step+1 });
			}
		}
		if (n % 2 == 0) {
			if (chk[n / 2] == false) {
				chk[n / 2] = true;
				q.push({ n / 2,step + 1 });
			}
		}
		if (chk[n - 1] == false) {
			chk[n - 1] = true;
			q.push({ n - 1,step + 1 });
		}
	}
	printf("%d\n", ans);
	return 0;
}