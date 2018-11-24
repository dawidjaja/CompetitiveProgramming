#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

map <char, int> cek;
char kata[205];
int n, ans, tmp;

int main() {
	scanf("%d", &n);
	// getchar();
	scanf("%s", kata);
	tmp = 0;
	ans = 0;
	for(int i = 0; i < n; i++) {
		if('a' <= kata[i] && kata[i] <= 'z') {
			if(!cek.count(kata[i])) {
				cek[kata[i]] = 1;
				tmp++;
			}
		} else if('A' <= kata[i] && kata[i] <= 'Z') {
			cek.clear();
			ans = max(tmp, ans);
			tmp = 0;
		}
	}
	printf("%d\n", max(tmp, ans));
	return 0;
}