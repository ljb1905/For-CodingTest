#include <stdio.h>

int main() {
	long long n; scanf("%lld", &n);
	long long mod = 1000000007;
	long long arr[2][2] = { {1,1},{1,0} };
	long long tmp[2][2] = { {1,0},{0,1} };
	long long ans[2][2] = { {1,0},{0,1} };

	n -= 1;
	while (n > 0) {
		if (n % 2 == 1) { //ans에 arr를 곱하고 tmp에 저장
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					long long sum = 0;
					for (int k = 0; k < 2; k++) {
						sum += arr[i][k] * ans[k][j];
						sum %= mod;
					}
					tmp[i][j] = sum;
				}
			}

			for (int i = 0; i < 2; i++) { //tmp를 다시 ans로 옮겨줌
				for (int j = 0; j < 2; j++) {
					ans[i][j] = tmp[i][j];
				}
			}
		}

		for (int i = 0; i < 2; i++) { //arr를 제곱해서 tmp에 저장
			for (int j = 0; j < 2; j++) {
				long long sum = 0;
				for (int k = 0; k < 2; k++) {
					sum += arr[i][k] * arr[k][j];
					sum %= mod;
				}
				tmp[i][j] = sum;
			}
		}

		for (int i = 0; i < 2; i++) { //tmp를 다시 arr로 옮겨줌
			for (int j = 0; j < 2; j++) {
				arr[i][j] = tmp[i][j];
			}
		}
		n /= 2;
	}

	printf("%lld\n", (ans[1][0]+ans[1][1])%mod);
	return 0;
}