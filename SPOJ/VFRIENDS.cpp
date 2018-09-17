#include <algorithm>
#include <cstdio>

using namespace std;

void bikin(int skrg, int l, int r) {
	lazy[skrg] = 0;
	if(l == r) {
		st[skrg] = list[l];
		return;
	}
	int mid = (l + r) >> 1;
	bikin(skrg * 2, l, mid);
	bikin(skrg *2 + 1, mid + 1, r);
	st[skrg] = st[skrg * 2] + st[skrg * 2 + 1];
	return;
}

void ganti(int skrg, int l, int r, int x, int y, )

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &list[i]);
		}
		sort(list + 1, list + 1 + n);
		bikin(1, 1, n);
		for(int i = n; i >= 1; i--) {
			ganti(1, 1, n, i - list[i], i - 1, list[i]);
		}
	}
	return 0;
}