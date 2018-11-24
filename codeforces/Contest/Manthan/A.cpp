#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

int n;
char nama[105];
map <string, int> cek;

int main() {
	scanf("%d", &n);
	getchar();
	for(int i = 1; i <= n; i++) {
		scanf("%s", nama);
		getchar();
		if(cek.count(nama)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
		cek[nama] = 1;
	}
	return 0;
}