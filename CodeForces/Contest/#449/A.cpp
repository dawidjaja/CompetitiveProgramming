#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int n, m, l, r;
char s[205];
char a, b;

int main() {
	scanf("%d%d", &n, &m);
	getchar();
	scanf("%s", s);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &l, &r);
		getchar();
		a = getchar();
		getchar();
		b = getchar();
		// cout << a << b;
		for(int i = l - 1; i < r; i++) {
			if(s[i] == a) {
				s[i] = b;
			}
		}
	}
	cout << s << endl;
	return 0;
}