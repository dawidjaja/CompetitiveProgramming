#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int n, k, blkg, dpn;
char s[200005];

int main() {
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	dpn = blkg = (n - k) / 2;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(' && dpn) {
			dpn--;
			continue;
		}
		if (s[i] == ')' && blkg) {
			blkg--;
			continue;
		}
		printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}