#include <stdio.h>
#include <algorithm>
using namespace std;

struct strr {
	int idx, age;
	char namm[101];
	bool operator < (const strr & o)const {
		if (age == o.age) {
			return idx < o.idx;
		}
		return age < o.age;
	}
}arr[100001];

int main()
{
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		arr[i].idx = i;
		scanf("%d %s", &arr[i].age, arr[i].namm);
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", arr[i].age, arr[i].namm);
	}
	return 0;
}