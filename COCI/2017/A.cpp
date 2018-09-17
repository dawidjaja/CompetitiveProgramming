#include <algorithm>
#include <cstdio>
using namespace std;

int n, temp, list[1000005];
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &temp);
		list[temp]++;
	}
	int ctr = 0;
	for(int i = 1000000; i >= 0 ; i--) {
		ctr += list[i];
		if(ctr >= i) {
			printf("%d", i);
			return 0;
		}
	}
}
