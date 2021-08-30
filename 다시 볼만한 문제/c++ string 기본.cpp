#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string arr[51];
int zcnt[51];
int ans;

int main() {
    int n, m, k; cin >> n >> m;
	for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
            if (arr[i][j] == '0') zcnt[i]++;
	}
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        int tmp = 0;
        if (zcnt[i] <= k && zcnt[i] % 2 == k % 2)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                    tmp++;
            }
        }
        ans = max(tmp, ans);
    }
    cout << ans;
	return 0;
}