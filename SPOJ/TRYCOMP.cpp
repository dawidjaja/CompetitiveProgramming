#include <algorithm>
#include <cstdio>

#define getchar() getchar_unlocked()

using namespace std;

int n, q, pjg, ans, a;
char kata[20], dum;

struct node {
	node* adj[30];
	int brp, bgs, apa;
};

inline int baca() {
	int temp = 0;
	char c;
	c = getchar();
	while(c < '0' || c > '9') {
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		temp *= 10;
		temp += c - '0';
		c = getchar();
	}
	return temp;
}

node* root;

inline node* newnode(int x){
	node* temp;
	temp = new node();
	for(int i = 0; i <= 26; i++) {
		temp->adj[i] = NULL;
	}
	temp->brp = 0;
	temp->bgs = -1;
	temp->apa = -1;
	return temp;
}

node* insert(node* skrg, char kata[], int x) {
	if(skrg == NULL) {
		skrg = newnode(kata[x]-a);
	}
	if(x == pjg-1) {
		skrg->brp++;
		if(skrg->brp >= skrg->bgs) {
			skrg->bgs = skrg->brp;
			skrg->apa = 0;
		}
		return skrg;
	} else {
		int idx = kata[x+1] - a;
		skrg->adj[idx] = insert(skrg->adj[idx], kata, x+1);
		if(skrg->adj[idx]->bgs >= skrg->bgs) {
			if(skrg->adj[idx]->bgs == skrg->bgs) {
				skrg->apa = min(skrg->apa, idx);
			} else {
				skrg->bgs = skrg->adj[idx]->bgs;
				skrg->apa = idx;
			}
		}
		return skrg;
	}
	
}

int cari(node* skrg, int x) {
	if(skrg == NULL) {
		return -1;
	}
	if(x > pjg) {
		if(skrg->apa == 0) {
			return skrg->brp;
		} else {
			printf("%c", skrg->apa + a);
			return cari(skrg->adj[skrg->apa], x+1);
		}
	} else if(x == pjg) {
		for(int i = 0; i < pjg; i++) {
			printf("%c", kata[i]);
		}
		if(skrg->apa == 0) {
			return skrg->brp;
		} else {
			printf("%c", skrg->apa + a);
			return cari(skrg->adj[skrg->apa], x+1);
		}
	} else {
		return cari(skrg->adj[kata[x] - a], x+1);
	}
}

int main() {
//	scanf("%d", &n);
	n = baca();
	a = 'a'-1;
	root = new node();
	root = newnode(0);
	for(int i = 1; i <= n; i++) {
		dum = getchar();
		while(dum < 'a' || dum > 'z') {
			dum = getchar();
		}
		pjg = 0;
		while(dum >= 'a' && dum <= 'z') {
			kata[pjg++] = dum;
			dum = getchar();
		}
		root = insert(root, kata, -1);
	}
	scanf("%d", &q);
//	q = baca();
	while(q--){
		dum = getchar();
		while(dum < 'a' || dum > 'z') {
			dum = getchar();
		}
		pjg = 0;
		while(dum >= 'a' && dum <= 'z') {
			kata[pjg++] = dum;
			dum = getchar();
		}
		
		ans = cari(root, 0);
		if(ans != -1) {
			printf(" %d\n", ans);
		} else {
			printf("-1\n");
		}
	}
}

