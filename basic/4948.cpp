#include <stdio.h>

const int VAL = 123456 * 2 + 1;
bool notPrime[VAL];

int main()
{
    for (int i = 2; i * i <= VAL; i++) {
        for (int j = i + i; j <= VAL; j += i) {
            notPrime[j] = true;
        }
    }
    notPrime[1] = true;
    while (1) {
        int ans = 0;
        int n; scanf("%d", &n);
        if (n == 0) {
            return 0;
        }
        for (int i = n + 1; i <= 2 * n; i++) {
            if (!notPrime[i]) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}