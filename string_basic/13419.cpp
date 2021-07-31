#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		char arr[30]; scanf("%s", arr);
		vector<char> v[2];
		int l = strlen(arr);
		if (l % 2 == 0) {
			for (int i = 0; i < l; i += 2) {
				v[0].push_back(arr[i]);
			}
			for (int i = 1; i < l; i += 2) {
				v[1].push_back(arr[i]);
			}
		}
		else {
			for (int i = 0; i < l; i += 2) {
				v[0].push_back(arr[i]);
			}
			for (int i = 1; i < l; i += 2) {
				v[0].push_back(arr[i]);
			}
			for (int i = 1; i < l; i += 2) {
				v[1].push_back(arr[i]);
			}
			for (int i = 0; i < l; i += 2) {
				v[1].push_back(arr[i]);
			}
		}
		for (int i = 0; i < v[0].size(); i++) {
			printf("%c", v[0][i]);
		}
		printf("\n");
		for (int i = 0; i < v[1].size(); i++) {
			printf("%c", v[1][i]);
		}
		printf("\n");
	}
	return 0;
}