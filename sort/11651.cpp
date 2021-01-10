#include <stdio.h>
#include <algorithm>
using namespace std;

struct s {
	int x, y;
	s(){}
	s(int x,int y)
		:x(x),y(y)
	{}
	bool operator < (const s& o)const {
		if (y == o.y)
			return x < o.x;
		return y < o.y;
	}
}arr[100001];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	return 0;
}