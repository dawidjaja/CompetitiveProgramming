#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

char kata[105], tes[105];
int a, b, n;

int main() {
	scanf("%s", kata);
	a = b = 0;
	scanf("%d", &n);
	getchar();
	for(int i = 1; i <= n; i++) {
		scanf("%s", tes);
		// cout << tes << endl;
		if(tes[1] == kata[0]) {
			b = 1;
		}
		if(tes[0] == kata[1]) {
			a = 1;
		}
		if(tes == kata) {
			a = b = 1;
		}
	}
	if(a && b) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}