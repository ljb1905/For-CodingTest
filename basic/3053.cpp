#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>

int main()
{
	int n; scanf("%d", &n);
	double ans1 = n * n * M_PI;
	double ans2 = n * n * 2;
	printf("%.6lf\n%.6lf\n",ans1,ans2);
	
	return 0;
}