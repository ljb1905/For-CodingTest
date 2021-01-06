#include <stdio.h>

const int VAL = 10001;
bool notPrime[VAL];

int main()
{
    for (int i = 2; i * i <= VAL; i++) {
        for (int j = i + i; j <= VAL; j += i) {
            notPrime[j] = true;
        }
    }
    notPrime[1] = true;
    int t; scanf("%d", &t);
    while (t--){
        int n; scanf("%d", &n);
        int a = n / 2, b = n / 2;
        while (1) {
            if (!notPrime[a] && !notPrime[b]) {
                printf("%d %d\n", a, b);
                break;
            }
            a--;
            b++;
        }
    }
    return 0;
}