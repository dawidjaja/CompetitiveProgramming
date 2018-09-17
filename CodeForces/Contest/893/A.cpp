#include <algorithm>
#include <cstdio>

using namespace std;

int n, list[10], x; 	

int main() {
	scanf("%d", &n);
	list[1] = list[2] = 1;
	list[3] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if(list[x] == 0) {
			printf("NO\n");
			return 0;
		}
		for(int j = 1; j <= 3; j++) {
			if(j != x) {
				list[j] ^= 1;
			}
		}
	}
	printf("YES\n");
	return 0;
}