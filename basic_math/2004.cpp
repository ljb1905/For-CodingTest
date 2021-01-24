#include <stdio.h>
#include <algorithm>
using namespace std;

int func(int stan, int n) { //팩토리얼 안에 stan의 개수
	int ret = 0;
	
	for (long long i = stan; n / i >= 1; i *= stan) {
		ret += n / i;
	}

	return ret;
}

int main() 
{
	int n, m; scanf("%d %d", &n, &m);
	int n_5 = func(5, n);
	int n_2 = func(2, n);
	int nm_5 = func(5, n - m);
	int nm_2 = func(2, n - m);
	int m_5 = func(5, m);
	int m_2 = func(2, m);
	printf("%d\n", min(n_5 - nm_5 - m_5, n_2 - nm_2 - m_2));
	return 0;
}