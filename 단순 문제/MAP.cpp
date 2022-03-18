#include <stdio.h>
#include <map>
#include <string>

using namespace std;

int main()
{
	int t; scanf("%d", &t);
	while (t--) {
		map<string, int> m;
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			char a[22], b[22];
			scanf("%s %s", a, b);
			if (m.count(b)) { // 이미 존재할 때
				m[b]++;
				// 개수만 늘려줌
			}
			else {
				m.insert(make_pair(b, 1));
				// 새로 만들어서 넣어줌
			}
		}
		int ans = 1;
		map<string, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			//for (auto it = clothes.begin(); it != clothes.end(); ++it)도 가능
			ans *= (it->second + 1);
			//개수 +1개
		}
		printf("%d\n", ans - 1);
	}
	return 0;
}