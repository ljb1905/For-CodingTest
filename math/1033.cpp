#include <stdio.h>
#include <vector>
using namespace std;

long long arr[11][5];
long long val[11];
long long GCD(long long a, long long b) { return a % b == 0 ? b : GCD(b, a % b); }
vector<int> v[11];
bool chk[11];

void dfs(int now, int cant, long long inc) {
    if (chk[now]) return;
    if (now != cant)
        val[now] *= inc;
    chk[now] = true;
    for (int i = 0; i < v[now].size(); i++) {
        int next = v[now][i];
        if (!chk[next])
            dfs(next, cant, inc);
    }
}


int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%lld %lld %lld %lld", &arr[i][0], &arr[i][1], &arr[i][2], &arr[i][3]);
        long long tmp = GCD(arr[i][2], arr[i][3]);
        arr[i][2] /= tmp;
        arr[i][3] /= tmp;
    }
    for (int i = 0; i < n; i++) {
        val[i] = 1;
    }
    for (int i = 0; i < n - 1; i++) {
        long long tmp1 = val[arr[i][0]];
        long long tmp2 = val[arr[i][1]];
        long long div = GCD(tmp1, tmp2);
        long long inc1 = tmp2 * arr[i][2] / div;
        long long inc2 = tmp1 * arr[i][3] / div;
        /*val[arr[i][0]] = tmp1 * inc1;
        val[arr[i][1]] = tmp2 * inc2;*/
        dfs(arr[i][0], arr[i][1], inc1);
        for (int i = 0; i < n; i++) chk[i] = false;
        dfs(arr[i][1], arr[i][0], inc2);
        for (int i = 0; i < n; i++) chk[i] = false;
        v[arr[i][0]].push_back(arr[i][1]);
        v[arr[i][1]].push_back(arr[i][0]);
    }
    long long gcd = val[0];
    for (int i = 0; i < n; i++) {
        gcd = GCD(gcd, val[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        printf("%lld ", val[i] / gcd);
    }
    printf("%lld\n", val[n - 1] / gcd);
    return 0;
}