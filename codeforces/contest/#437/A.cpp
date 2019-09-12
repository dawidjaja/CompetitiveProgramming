#include <algorithm>
#include <cstdio>


using namespace std;

int n, s, f;
char a, b;

int main() {
	scanf("%d", &n);
	getchar();
	a = getchar();
	for(int i = 1; i < n; i++) {
		b = getchar();
		if(a == 'S' && b == 'F') {
			s++;
		} else if (a == 'F' && b == 'S') {
			f++;
		}
		a = b;
	}
	if(s > f) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}