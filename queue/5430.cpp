#include <stdio.h>
#include <deque>
#include <string.h>
using namespace std;

char inp[100001];
int arr[100001];

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		deque <int> dq;
		scanf("%s", inp);
		int n; scanf("%d", &n);
		getchar();
		getchar();
		for (int i = 0; i < n-1; i++) {
			scanf("%d,", &arr[i]);
		}
		if(n>0)
			scanf("%d,", &arr[n-1]);
		getchar();
		getchar();

		for (int i = 0; i < n; i++) {
			dq.push_back(arr[i]);
		}
		int l = strlen(inp);
		bool sw = false;
		bool anschk = false;
		for (int i = 0; i < l; i++) {
			if (inp[i] == 'R') {
				sw = !sw;
			}
			else {
				if (sw == false) {
					if (dq.empty()) {
						anschk = true;
						break;
					}
					dq.pop_front();
				}
				else {
					if (dq.empty()) {
						anschk = true;
						break;
					}
					dq.pop_back();
				}
			}
		}
		if (anschk) {
			printf("error\n");
		}
		else if(sw==false){
			printf("[");
			while (dq.size() > 1) {
				printf("%d,", dq.front());
				dq.pop_front();
			}
			if (dq.size() == 1) {
				printf("%d", dq.front());
			}
			printf("]\n");
		}
		else if (sw == true) {
			printf("[");
			while (dq.size() > 1) {
				printf("%d,", dq.back());
				dq.pop_back();
			}
			if (dq.size() == 1) {
				printf("%d", dq.back());
			}
			printf("]\n");
		}
	}
	return 0;
}