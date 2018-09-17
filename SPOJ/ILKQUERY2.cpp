#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct node {
	node* l;
	node* r;
	int s, n, p;
};
map <int, vector<int> > v;
map <int, node* > root;
map <int, int> ada;
vector <int> pend;
int n, q, list[100005], tipe, a, b, ans, k, r;


struct node* newnode(int x) {
	node* temp;
	temp = new node();
	temp->l = NULL;
	temp->r = NULL;
	temp->s = 1;
	temp->n = x;
	temp->p = 1;
	return temp;
}

inline int getN(node* skrg) {
	if(skrg == NULL) {
		return -1;
	}
	return skrg->n;
}

inline int getS(node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->s;
}

inline int getP(node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->p;
}

inline void updateS(node* skrg) {
	skrg->s = getS(skrg->l) + getS(skrg->r) + getP(skrg);
}

struct node* bikin(struct node* skrg, int kiri, int kanan, int x) {
	if(kiri > kanan) {
		return NULL;
	}
	if(kiri == kanan) {
		skrg = newnode(v[x][kiri]);
		return skrg;
	}
	int tgh = (kiri + kanan) / 2;
	skrg = newnode(v[x][tgh+1]);
	skrg->l = bikin(skrg->l, kiri, tgh, x);
	skrg->r = bikin(skrg->r, tgh+2, kanan, x);
	updateS(skrg);
	return skrg;
}

void update(node* skrg, int x) {
	if(getN(skrg) == x) {
		skrg->p = 1 - getP(skrg);
		updateS(skrg);
		return;
	}
	if(x < getN(skrg)) {
		update(skrg->l, x);
	} else {
		update(skrg->r, x);
	}
	updateS(skrg);
	return;
}

int itung(node* skrg, int x) {
	if(skrg == NULL) {
		return 0;
	}
	if(getN(skrg) == x) {
		return getS(skrg->l) + getP(skrg);
	}
	if(x < getN(skrg)) {
		return itung(skrg->l, x);
	} else {
		return getS(skrg->l) + getP(skrg) + itung(skrg->r, x);
	}
}

void tulis(node* skrg) {
	if(skrg == NULL) {
		return;
	}
	printf("---  %d --> %d %d \n", getN(skrg), getN(skrg->l), getN(skrg->r));
	tulis(skrg->l);
	tulis(skrg->r);
}

int main() {
	scanf("%d%d", &n, &q);
	for(int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
		v[list[i]].push_back(i);
		if(!ada.count(list[i])) {
			pend.push_back(list[i]);
			ada[list[i]] = 1;
		}
	}
	for(int i = 0; i < pend.size(); i++) {
		root[pend[i]] = new node();
		root[pend[i]] = bikin(root[pend[i]], 0, v[pend[i]].size()-1, pend[i]);
//		printf("%d -- > %d\n", pend[i], getN(root[pend[i]]));
//		tulis(root[pend[i]]);
	}
	while(q--) {
		scanf("%d", &tipe);
		if(tipe) {
			scanf("%d", &r);
			update(root[list[r]], r);
		} else {
			scanf("%d%d%d", &a, &b, &k);
			if(root.count(k)) {
				ans = itung(root[k], b) - itung(root[k], a-1);
				printf("%d\n", ans);
			} else {
				printf("0\n");
			}
		}
	}
	return 0;
}
