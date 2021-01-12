#include <stdio.h>
#include <string.h>

int main()
{
	int n; scanf("%d", &n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		char arr[101]; scanf("%s", arr);
		bool chk[27] = { false, };
		int l = strlen(arr);
		bool chkans = true;
		chk[arr[0] - 'a'] = true;
		for (int i = 1; i < l; i++) {
			if (arr[i] == arr[i - 1])
				continue;
			int now = arr[i] - 'a';
			if (chk[now] == false)
				chk[now] = true;
			else {
				chkans = false;
				break;
			}
		}
		if (chkans)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}