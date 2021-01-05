#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

bool notPrime[10000001];
vector <int> v;

int main()
{
    for (int i = 2; i * i <= 10000001; i++) {
        for (int j = i + i; j <= 10000001; j += i) {
            notPrime[j] = true;
        }
    }
    int ans = 0;
    notPrime[1] = true;
    int n; scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        if (!notPrime[i]) {
            v.push_back(i);
        }
    }
    while (n != 1) {
        for (int i = 0; i < v.size(); i++) {
            int now = v[i];
            if (n % now == 0) {
                printf("%d\n", now);
                n /= now;
                break;
            }
        }
    }
    return 0;
}