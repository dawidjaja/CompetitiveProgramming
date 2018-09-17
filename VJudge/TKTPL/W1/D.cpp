#include <algorithm>
#include <cstdio>

using namespace std;

void bikin(int idx, int ki, int ka) {
	if(ki == ka) {
		l[idx] = list[ki].fs - list[ki].sc;
		r[idx] = list[ki].fs + list[ki].sc;
		return;
	}
	int tgh = (ki + ka) >> 1;
	bikin(idx * 2, ki, tgh);
	bikin(idx * 2 + 1, tgh + 1, ka);
	l[idx] = min(l[idx * 2], l[idx * 2 + 1]);
	r[idx] = max(r[idx * 2], r[idx * 2 + 1]);
	return;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &list[i].fs, &list[i].sc);
	}
	sort(list + 1, list + 1 + n);
	bikin(1, 1, n);
	for(int i = 1; i <= n; i++) {
		
	}
	return 0;
}