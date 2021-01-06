#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	int w, h, x, y; scanf("%d %d %d %d", &w, &h, &x, &y);
	int minx = min(x - w,w);
	int miny = min(y - h, h);
	printf("%d\n", min(minx, miny));
	return 0;
}