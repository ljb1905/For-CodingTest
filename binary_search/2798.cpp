#include <stdio.h>
#include <algorithm>
using namespace std;

int arr[101];

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	int sum = 0;
	int min = 987654321;
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			sum = arr[i] + arr[j];
			int l = j + 1;
			int r = n - 1;
			int mid = (l + r) / 2;
			while (l <= r) {
				mid = (l + r) / 2;
				int tmp = arr[mid];
				int cha = m - (sum + tmp);
				if (cha >= 0 && cha < min) {
					min = cha;
				}
				if (cha > 0) {
					l = mid + 1;
				}
				else if (cha < 0) {
					r = mid - 1;
				}
				else break;	
			}
		}
	}
	printf("%d\n", m-min);
	return 0;
}