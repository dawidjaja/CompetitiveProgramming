#include <algorithm>
#include <cstdio>
#include <random>

using namespace std;

int vis[100005], list[100005], cek, n, a, b, idx[100005];

void jln(int skrg, int x) {
	if(vis[skrg] == 1) {
		if(x == 0) {
			return;
		} else {
			cek = 0;
			return;
		}
	} else {
		vis[skrg] = 1;
		idx[skrg] = x;
		jln(list[skrg], x ^ 1);
	}
	return;
}

int main() {
	scanf("%d", &n);

	cek = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		if(i == list[i]) {
			cek = i;
			break;
		}
	}
	if(cek) {
		printf("YES\n");
		for(int i = 1; i <= n; i++) {
			if(i == cek) {
				continue;
			}
			printf("%d %d\n", i, cek);
		}
		return 0;
	}
	int tes = 0;
	for(int i = 1; i <= n; i++) {
		if(list[list[i]] == i) {
			a = i;
			b = list[i];
			tes = 1;
			vis[a] = -1;
			vis[b] = -1;
			break;
		}
	}
	if(tes == 0) {
		printf("NO\n");
		return 0;
	}
	cek = 1;
	for(int i = 1; i <= n; i++) {
		if(vis[i] == 0) {
			jln(i, 0);
			if(cek == 0) {
				break;
			}
		}
	}
	if(cek) {
		printf("YES\n");
		for(int i = 1; i <= n; i++) {
			if(vis[i] == -1) {
				continue;
			}
			printf("%d %d\n", i, idx[i] == 0 ? a : b);
		}
		printf("%d %d\n", a, b);
	} else {
		printf("NO\n");
	}
	return 0;
}
