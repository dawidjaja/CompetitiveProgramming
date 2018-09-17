#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

int n, skrg;
pii list[1005];

int main() {
	scanf("%d", &n);
	skrg = 0;
	for(int i = 1; i <= n; i++) {
		skrg++;
		scanf("%d%d", &list[i].fs, &list[i].sc);
		while(skrg < list[i].fs){
			skrg++;
		}
		while((skrg - list[i].fs) % list[i].sc != 0) {
			skrg++;
		}
	}
	printf("%d\n", skrg);
	return 0;
}