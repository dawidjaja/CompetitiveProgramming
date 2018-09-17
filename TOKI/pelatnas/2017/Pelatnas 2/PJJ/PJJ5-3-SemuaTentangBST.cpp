#include <algorithm>
#include <cstdio>

using namespace std;

struct node {
	node* kiri;
	node* kanan;
	int h, num;
};

int p[100005], n, atas, hsl[100005], a, b;
node* list[100005];

int par(int x) {
	if(p[x] == x) {
		return x;
	} else {
		return par(p[x]);
	}
}

inline void init() {
	list[0] = NULL;
	for(int i = 1; i <= n; i++) {
		list[i] = new node();
		list[i]->h = 1;
		list[i]->num = i;
		p[i] = i;
	}
}

inline int getH(struct node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->h;
}

inline int getN(struct node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->num;
}

inline void updateH(struct node* skrg)  {
	skrg->h = max(getH(skrg->kiri), getH(skrg->kanan)) + 1;
}

void tinggi(struct node* skrg) {
	if(skrg == NULL) {
		return;
	}
	tinggi(skrg->kiri);
	tinggi(skrg->kanan);
	updateH(skrg);
	return;
}

void dfs(struct node* skrg, int ki, int ka, int tinggi) {
	if(skrg == NULL) {
		return;
	}
	if(skrg == list[atas]) {
		hsl[getN(skrg)] = skrg->h;
	} else {
		hsl[getN(skrg)] = max(max(getH(skrg->kiri) + ki, getH(skrg->kanan) + ka), max(getH(skrg), tinggi + 1));
	}
	dfs(skrg->kiri, ki, ka + 1, max(tinggi, getH(skrg->kanan) + ka));
	dfs(skrg->kanan, ki + 1, ka, max(tinggi, getH(skrg->kiri) + ki));
	return;
}

int main() {
	scanf("%d", &n);
	init();
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &a, &b);
		list[i]->kiri = list[a];
		list[i]->kanan = list[b];
		p[a] = i;
		p[b] = i;
	}
	atas = par(1);
	tinggi(list[atas]);
	dfs(list[atas], 1, 1, 1);
	for(int i = 1; i <= n; i++) {
		printf("%d\n", hsl[i]);
	}
	return 0;
}
