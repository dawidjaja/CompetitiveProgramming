#include <algorithm>
#include <cstdio>

using namespace std;

int h1, a1, c1, h2, a2, list[100005], ctr;

int main() {
	scanf("%d%d%d", &h1, &a1, &c1);
	scanf("%d%d", &h2, &a2);
	while(true){
		// printf("%d %d\n", h1, a2);
		if(h2 <= 0) {
			break;
		}
		ctr++;
		if(h1 <= a2 && h2 > a1) {
			h1 += c1;
			list[ctr] = 1;
		} else {
			h2 -= a1;
			list[ctr] = 2;
		}
		h1 -= a2;
	}
	printf("%d\n", ctr);
	for(int i = 1; i <= ctr; i++) {
		if(list[i] == 1) {
			printf("HEAL\n");
		} else {
			printf("STRIKE\n");
		}
	}
	return 0;
}