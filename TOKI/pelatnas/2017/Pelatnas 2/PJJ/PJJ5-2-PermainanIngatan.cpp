#include <algorithm>
#include <cstdio>

using namespace std;

int q, x, ans;
char perintah;

struct node {
	int s, h, num;
	node* kiri;
	node* kanan;
};

struct node* atas;

struct node* newnode(int x) {
	struct node* temp;
	temp = new node();
	temp->kanan = NULL;
	temp->kiri = NULL;
	temp->h = 1;
	temp->s = 1;
	temp->num = x;
	return temp;
}

inline int getN(struct node* skrg) {
	if(skrg == NULL) return 0;
	return skrg->num;
}

inline int getS(struct node* skrg) {
	if(skrg == NULL) return 0;
	return skrg->s;
}

inline int getH(struct node* skrg) {
	if(skrg == NULL) return 0;
	return skrg->h;
}

inline int getB(struct node* skrg) {
	if(skrg == NULL) return 0;
	return getS(skrg->kanan) - getS(skrg->kiri);
}

inline void updateH(struct node* skrg) {
	skrg->h =  max(getH(skrg->kiri), getH(skrg->kanan))+1;
}

inline void updateS(struct node* skrg) {
	skrg->s = getS(skrg->kiri) + getS(skrg->kanan) + 1;
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

struct node* masuk(struct node* skrg, int x) {
	if(skrg == NULL) {
		skrg = newnode(x);
		return skrg;
	}
	
	if(getN(skrg) == x) {
		return skrg;
	}
	
	if(x < getN(skrg)) {
		skrg->kiri = masuk(skrg->kiri, x);
	} else if(x > getN(skrg)) {
		skrg->kanan = masuk(skrg->kanan, x);
	}
	updateH(skrg);
	updateS(skrg);
	int dif, brt;
	dif = getB(skrg);
	if(dif >= 2) {
		brt = getB(skrg->kanan);
		if(brt <= 0) {
			skrg->kanan = rotateR(skrg->kanan);
		}
		return rotateL(skrg);
	} else if(dif <= -2) {
		brt = getB(skrg->kiri);
		if(brt >= 0) {
			skrg->kiri = rotateL(skrg->kiri);
		}
		return rotateR(skrg);
	}
	return skrg;
}

struct node* minval(struct node* skrg) {
	node* temp;
	temp = skrg;
	while(temp->kiri != NULL) {
		temp = temp->kiri;
	}
	return temp;
}

struct node* apus(struct node* skrg, int x) {
	if(skrg == NULL) {
		return skrg;
	}
	
	if(getN(skrg) == x) {
		if(skrg->kiri == NULL || skrg->kanan == NULL) {
			if(skrg->kiri == skrg->kanan) {
				skrg = NULL;
			} else {
				struct node* temp;
				if(skrg->kiri == NULL) {
					temp = skrg->kanan;
				} else {
					temp = skrg->kiri;
				}
				*skrg = *temp;
				free(temp);
			}
		} else {
			struct node* temp;
			temp = minval(skrg->kanan);
			skrg->num = temp->num;
			skrg->kanan = apus(skrg->kanan, getN(temp));
		}
	} else if(x < getN(skrg)) {
		skrg->kiri = apus(skrg->kiri, x);
	} else {
		skrg->kanan = apus(skrg->kanan, x);
	}
	if(skrg == NULL) {
		return skrg;
	}
	updateH(skrg);
	updateS(skrg);
	int dif, brt;
	dif = getB(skrg);
	if(dif>=2) {
		brt = getB(skrg->kanan);
		if(brt <= 0) {
			skrg->kanan = rotateR(skrg->kanan);
		}
		return rotateL(skrg);
	} else if(dif <= -2) {
		brt = getB(skrg->kiri);
		if(brt >= 0) {
			skrg->kiri = rotateL(skrg->kiri);
		}
		return rotateR(skrg);
	}
	return skrg;
}

int cari(struct node* skrg, int x) {
	if(skrg == NULL) {
		return 0;
	}
	if(getN(skrg) == x){
		return getS(skrg->kiri) + 1;
	} else if(getN(skrg) < x) {
		return getS(skrg->kiri) + 1 + cari(skrg->kanan, x);
	} else {
		return cari(skrg->kiri, x);
	}
}

void debug(struct node* skrg) {
	if(skrg == NULL) return;
	printf("%d --> %d %d\n", getN(skrg), getN(skrg->kiri), getN(skrg->kanan));
	if(skrg->kiri != NULL) debug(skrg->kiri);
	if(skrg->kanan != NULL) debug(skrg->kanan);
	return;
}

int main() {
	scanf("%d", &q);
	atas = new node();
	atas = NULL;
	while(q--) {
		getchar();
		scanf("%c%d", &perintah, &x);
		if(perintah == 'R') {
			atas = masuk(atas, x);
		} else if(perintah == 'F') {
			atas = apus(atas, x);
		} else if(perintah == 'C') {
			ans = cari(atas, x-1);
			printf("%d\n", ans);
		}
		printf("-- %d --\n", getN(atas));
		debug(atas);
		printf("\n");
	}
	return 0;
}
