#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

int main() {
	while (1) {
		char arr[110] = { 0, };
		stack <char> s;
		scanf("%[^\n]", arr);
		getchar(); // 한줄입력 + 버퍼비우기
		if (strcmp(arr, ".") == 0) // .인지 비교
			break;
		int l = strlen(arr);
		bool ans = true;
		for (int i = 0; i < l; i++) {
			if (arr[i] == '(' || arr[i] == '[') {
				s.push(arr[i]);
			}
			else if (arr[i] == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					ans = false;
				}
			}
			else if (arr[i] == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					ans = false;
				}
			}
			if (ans == false) {
				break;
			}
		}
		if (!s.empty())
			ans = false;
		if (ans)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}