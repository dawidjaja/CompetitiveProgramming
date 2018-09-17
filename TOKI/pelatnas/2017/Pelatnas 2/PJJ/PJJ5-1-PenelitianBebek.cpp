#include <algorithm>
#include <cstdio>

using namespace std;

struct node {
	int s, h, num;
	node* kiri;
	node* kanan;
	node* ortu;
};

int n, q, y, x, ans, N, p[100005];
node* list[100005];
char perintah;

struct node* newnode(int x) {
	node* temp;
	temp = new node();
	temp->ortu = temp;
	temp->kiri = NULL;
	temp->kanan = NULL;
	temp->s = 1;
	temp->h = 1;
	temp->num = x;
	return temp;
}

struct node* reset(struct node* skrg) {
	skrg->s = 1;
	skrg->h = 1;
	skrg->kiri = NULL;
	skrg->kanan = NULL;
	return skrg;
}

int par(int x) {
	if(p[x] == x) {
		return x;
	}
	p[x] = par(p[x]);
	return p[x];
}

inline void init() {
	for(int i = 1; i <= N; i++) {
		list[i] = newnode(i);
		p[i] = i;
	}
}

int getN(struct node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->num;
}

int getS(struct node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->s;
}

int getH(struct node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->h;
}

inline int getB(struct node* skrg) {
	if(skrg == NULL) return 0;
	return getH(skrg->kanan) - getH(skrg->kiri);
}

inline void updateH(struct node* skrg) {
	skrg->h =  max(getH(skrg->kiri), getH(skrg->kanan))+1;
}

inline void updateS(struct node* skrg) {
	skrg->s = getS(skrg->kiri) + getS(skrg->kanan) + 1;
}

inline void updateO(struct node* skrg) {
	if(skrg->kiri != NULL) {
		skrg->kiri->ortu = skrg->ortu;
	}
	if(skrg->kanan != NULL) {
		skrg->kanan->ortu = skrg->ortu;
	}
}

struct node* rotateR(struct node* skrg) {
	struct node* xL;
	xL = skrg->kiri;
	struct node* xLR;
	xLR = xL->kanan;
	
	skrg->kiri = xLR;
	xL->kanan = skrg;
	
	updateH(skrg);
	updateS(skrg);
	updateH(xL);
	updateS(xL);
	return xL;
}

struct node* rotateL(struct node* skrg) {
	struct node* xR;
	xR = skrg->kanan;
	struct node* xRL;
	xRL = xR->kiri;
	
	skrg->kanan = xRL;
	xR->kiri = skrg;
	
	updateH(skrg);
	updateS(skrg);
	updateH(xR);
	updateS(xR);
	return xR;
}

struct node* masuk(int a, int b) {
	if(list[a] == NULL) {
//		printf("---- %d %d ----\n", getN(a), x);
		list[b] = reset(list[b]);
		return list[b];
	}
//	printf("---- %d --> ( %d %d ) %d ----\n", getN(a), getN(a->kiri), getN(a->kanan), x);
	if(x < a) {
		list[a]->kiri = masuk(getN(list[a]->kiri), b);
//		printf("dalem ------ %d --> %d %d\n", getN(a), getN(a->kiri), getN(a->kanan));
	} else if(x > a) {
		list[a]->kanan = masuk(getN(list[a]->kanan), x);
	}
//	printf("------ %d --> %d %d\n", getN(a), getN(a->kiri), getN(a->kanan));
//	updateO(a);
	updateH(list[a]);
	updateS(list[a]);
	int dif, brt;
	dif = getB(list[a]);
	node* temp;
	if(dif >=2) {
		brt = getB(list[a]->kanan);
		if(brt <= 0) {
			list[a]->kanan = rotateR(list[a]->kanan);
		}
		return rotateL(list[a]);
//		b->ortu = temp->ortu;
//		return temp;
	} else if(dif <= -2) {
		brt = getB(list[a]->kiri);
		if(brt >= 0) {
			list[a]->kiri = rotateL(list[a]->kiri);
		}
		return rotateR(list[a]);
//		b->ortu = temp->ortu;
//		return temp;
	}
//	b->ortu = a->ortu;
	return list[a];
}

void jalan(int a, int b) {
	if(list[b]->kiri != NULL) {
		jalan(a, getN(list[b]->kiri));
	}
	if(list[b]->kanan != NULL) {
		jalan(a, getN(list[b]->kanan));
	}
//	printf("%d --> %d  asdfasdf\n", getN(a), getN(b));
	p[par(b)] = par(a);
	list[par(a)]->ortu = masuk(a, b);
//	printf("lol %d\n", getN(a->ortu));
	return;
}

void gabung(int aa, int bb) {
	node* a;
	node* b;
	a = list[aa]->ortu;
	b = list[bb]->ortu;
	if(getS(a) < getS(b)) {
		swap(a, b);
		swap(aa, bb);
	}
	p[par(bb)] = par(aa);
	jalan(aa, bb);
}

int cari(struct node* skrg, int n) {
//	printf("-- %d %d %d --\n", skrg->num, n, getS(skrg->kiri));
	if(n <= getS(skrg->kiri)) {
		return cari(skrg->kiri, n);
	} else if(n == getS(skrg->kiri) + 1) {
		return skrg->num;
	} else {
		return cari(skrg->kanan, n-getS(skrg->kiri)-1);
	}
}

void tultul(struct node* skrg) {
	printf("     %d --> %d %d\n", getN(skrg), getN(skrg->kiri), getN(skrg->kanan));
	if(skrg->kiri != NULL) {
		tultul(skrg->kiri);
	}
	if(skrg->kanan != NULL) {
		tultul(skrg->kanan);
	}
	return;
}

inline void debug() {
	for(int i = 1; i <= N; i++) {
		printf("%d --> %d\n", par(i), getN(list[par(i)]->ortu));
		tultul(list[par(i)]->ortu);
	}
}

int main() {
	scanf("%d%d", &N, &q);
	init();
	
	while(q--) {
		getchar();
		scanf("%c", &perintah);
		if(perintah == '@') {
			scanf("%d%d", &x, &y);
			gabung(par(x), par(y));
		} else if(perintah == '?') {
			scanf("%d%d", &x, &n);
			ans = cari(list[par(x)]->ortu, n);
			printf("%d\n", ans);
		}
		
		debug();
	}
	return 0;
}
