#include <stdio.h>
#include <algorithm>
using namespace std;

bool chk[4];

int main()
{
	int x[4], y[4];
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	sort(x, x + 3);
	sort(y, y + 3);
	int ansx;
	if (x[0] == x[1]) ansx = x[2];
	else ansx = x[0];
	int ansy;
	if (y[0] == y[1]) ansy = y[2];
	else ansy = y[0];
	printf("%d %d\n", ansx, ansy);
	return 0;
}