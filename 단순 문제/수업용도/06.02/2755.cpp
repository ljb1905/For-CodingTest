#include <stdio.h>

double score[5][3] = { {4.3,4.0,3.7},{3.3,3.0,2.7},{2.3,2.0,1.7},{1.3,1.0,0.7},{0.0,0.0,0.0} };

int main() {
	int n; scanf("%d", &n);
	double ans = 0;
	double sum = 0;
	for (int i = 0; i < n; i++) {
		char arr[101];
		int m;
		char brr[3];
		scanf("%s %d %s", arr, &m, brr);
		int idx1 = brr[0]-'A';
		int idx2 = 0;
		if (brr[1] == '0')
			idx2 = 1;
		else if (brr[1] == '-')
			idx2 = 2;
		ans += (double)m * score[idx1][idx2];
		sum += m;
	}
	ans += (double)0.0001;
	printf("%.2lf\n", ans / sum);
	return 0;
}