#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

map <int, int> cek;
int n, x, ctr, list[105];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x);
		if(!cek.count(x)) {
			list[ctr++] = x;
			cek[x]++;
		} else {
			cek[x]++;
		}
	}
	if(ctr != 2){ 
		printf("NO\n");
	} else {
		if(cek[list[0]] == cek[list[1]]) {
			printf("YES\n");
			printf("%d %d\n", list[0], list[1]);
		} else {
			printf("NO\n");
		}
	}
	return 0;
}