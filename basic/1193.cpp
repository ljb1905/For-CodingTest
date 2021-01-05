#include <stdio.h>

int main()
{
	int n; scanf("%d", &n);
	int val = 1;
	int now = 0;
	bool odd = false;
	while (now < n) {
		if (val % 2 == 1)
			odd = true;
		else
			odd = false;
		now += val;
		val++;
	}
	int mo, ja;
	if (odd == true) {
		mo = val - 1;
		ja = 1;
	}
	else
	{
		mo = 1;
		ja = val - 1;
	}	
	while (now != n) {
		now--;
		if (odd == true) {
			mo--;
			ja++;
		}
		else{
			ja--;
			mo++;
		}
	}
	printf("%d/%d", ja, mo);
	return 0;
}