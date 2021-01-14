#include <stdio.h>

int val[21][21][21];

int main()
{
	int a=1, b=1, c=1; 
	for (int i = 0; i <= 20; i++) {
		for (int j = 0; j <= 20; j++) {
			for (int z = 0; z <= 20; z++) {
				if (i == 0 || j == 0 || z == 0) {
					val[i][j][z] = 1;
				}
				else if (i < j && j < z) {
					val[i][j][z] = val[i][j][z - 1] + val[i][j - 1][z - 1] - val[i][j - 1][z];
				}
				else {
					val[i][j][z] = val[i - 1][j][z] + val[i - 1][j - 1][z] + val[i - 1][j][z - 1] - val[i - 1][j - 1][z - 1];
				}
			}
		}
	}
	while (1) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		if (a <= 0 || b <= 0 || c <= 0)
			printf("w(%d, %d, %d) = 1\n", a, b, c);
		else if (a > 20 || b > 20 || c > 20)
			printf("w(%d, %d, %d) = %d\n", a, b, c, val[20][20][20]);
		else {
			printf("w(%d, %d, %d) = %d\n", a, b, c, val[a][b][c]);
		}
	}
	return 0;
}