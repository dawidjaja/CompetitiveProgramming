#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int ls, lt, btg;
char s[200005], t[200005];

int main() {
	scanf("%d%d", &ls, &lt);
	getchar();
	scanf("%s", s);
	scanf("%s", t);
	btg = -1;
	for (int i = 0; i < ls; i++) {
		if(s[i] == '*') {
			btg = i;
			break;
		}
	}

	if (btg == -1) {
		// printf("%s %s %d\n", s, t, strcmp(s, t));
		if (strcmp(s, t) == 0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		return 0;
	} else {
		if (ls > lt + 1) {
			printf("NO\n");
		} else {
			int cek = 1;
			for (int i = 0; i < btg; i++) {
				if(s[i] != t[i]) {
					cek = 0;
				}
			}
			for (int i = 0; i <= (ls - btg - 1); i++) {
				if (s[ls - i] != t[lt - i]) {
					cek = 0;
				}
			}
			if (cek) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
		}
	}
	return 0;
}