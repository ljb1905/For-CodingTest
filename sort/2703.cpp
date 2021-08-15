#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[2250001];
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i * n + j]);
		}
	}
	sort(arr, arr + n * n);
	printf("%d\n", arr[(n-1)*n]);
	return 0;
}