#include <stdio.h>
#include <algorithm>
using namespace std;

struct line
{
	int stx, sty, edy;
	bool check; // 시작이면 true
	line(int stx=0, int sty=0, int edy=0,bool check=false) : stx(stx), sty(sty), edy(edy),check(check){}
	bool operator <(const line &o)const
	{
		return stx < o.stx;
	}
}arr[20001];
int seg[120001];
int cnt[120001];
int ans;

void sum(int node, int x, int y)
{
	if (cnt[node]>0) seg[node] = y - x + 1;
	else
	{
		if (x == y) seg[node] = 0;
		else seg[node] = seg[node * 2] + seg[node * 2 + 1];
	}
}
void update(int node, int start, int end, int x, int y, bool chk)
{
	if (y < start || end < x) return;
	int val = -1;
	if (chk == true) val = 1;
	if (x <= start && end <= y) cnt[node] += val;
	else
	{
		int mid = (start + end) / 2;
		update(node * 2, start, mid, x, y, chk);
		update(node * 2 + 1, mid+1, end, x, y, chk);
	}
	sum(node, start, end);
}

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < 2*n; i+=2)
	{
		int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
		arr[i] = line(a, b, d-1, true);
		arr[i + 1] = line(c, b, d-1, false);
	}
	sort(arr, arr + 2 * n);
	int past = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		if (i != 0)
		{
			int tmp = arr[i].stx - past;
			ans += tmp * seg[1];
		}
		update(1, 0, 30000, arr[i].sty, arr[i].edy, arr[i].check);
		past = arr[i].stx;
	}
	printf("%d\n", ans);
	return 0;
}