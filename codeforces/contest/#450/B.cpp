#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

int a, b, c, tmp, ctr;
map <int,int> cek[10];

int main() {
	scanf("%d%d%d", &a, &b, &c);
	while(true) {
		a *= 10;
		tmp = a / b;
		// printf("%d %d\n", a, tmp);
		a -= b * tmp;
		if(cek[tmp][a]) {
			printf("-1\n");
			return 0;
		}
		cek[tmp][a] = 1;
		ctr++;
		if(tmp == c) {
			printf("%d\n", ctr);
			return 0;
		}
	}
	return 0;
}