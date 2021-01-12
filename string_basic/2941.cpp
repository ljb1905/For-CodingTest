#include <stdio.h>
#include <string.h>

int main()
{
	char arr[111]; scanf("%s", arr);
	int l = strlen(arr);
	int cnt = 0;
	for (int i = 0; i < l; i++) {
		if (i == l - 1) {
			cnt++;
			break;
		}
		char now = arr[i];
		char next = arr[i + 1];
		bool chk = false;
		if (now == 'c' && next == '=')
			chk = true;
		else if (now == 'c' && next == '-')
			chk = true;
		else if (now == 'd' && next == '-')
			chk = true;
		else if (now == 'l' && next == 'j')
			chk = true;
		else if (now == 'n' && next == 'j')
			chk = true;
		else if (now == 's' && next == '=')
			chk = true;
		else if (now == 'z' && next == '=')
			chk = true;
		if (chk) {
			i++;
		}
		if (now == 'd' && next == 'z' && arr[i + 2] == '=') {
			i += 2;
		}
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}