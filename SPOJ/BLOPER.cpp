#include <algorithm>
#include <cstdio>

using namespace std;

int n, s, list[505], jmlh;

int main() {
	scanf("%d%d", &n, &s);
	jmlh = 0;
	for(int i = n; i >= 1; i--) {
		if(jmlh <= s) {
			jmlh += i;
			list[i] = 1;
		} else {
			jmlh -= i;
			list[i] = -1;
		}
	}
	if(list[1] == -1) {
		jmlh = 0;
		for(int i = n; i >= 1; i--) {
			if(jmlh < s) {
				jmlh += i;
				list[i] = 1;
			} else {
				jmlh -= i;
				list[i] = -1;
			}
		}
		if(list[1] == -1 || jmlh != s) {	
			printf("Impossible\n");
			return 0;
		}
		printf("1");
		for(int i = 2; i <= n; i++) {
			if(list[i] == 1) {
				printf("+");
			} else {
				printf("-");
			}
			printf("%d", i);
		}
		return 0;
	}
	if(list[1] == -1 || jmlh != s) {
		printf("Impossible\n");
		return 0;
	}
	printf("1");
	for(int i = 2; i <= n; i++) {
		if(list[i] == 1) {
			printf("+");
		} else {
			printf("-");
		}
		printf("%d", i);
	}
	return 0;
}
