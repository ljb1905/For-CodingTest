#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

const int VAL = 1000001;
bool notPrime[VAL];
vector <int> v;

int main()
{
    for (int i = 2; i * i <= VAL; i++) {
        for (int j = i + i; j <= VAL; j += i) {
            notPrime[j] = true;
        }
    }
    int ans = 0;
    notPrime[1] = true;
    int a, b; scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (!notPrime[i]) {
            v.push_back(i);
        }
    }
    for (int i = 0; i < v.size(); i++)
        printf("%d\n", v[i]);
    return 0;
}