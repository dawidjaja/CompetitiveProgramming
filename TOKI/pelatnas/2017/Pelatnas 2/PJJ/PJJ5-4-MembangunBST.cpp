#include <algorithm>
#include <cstdio>

using namespace std;

int  n, h, temp;

struct node {
	int num;
	node* kiri;
	node* kanan;
};

node* atas;

struct node* bikin(int l, int r, int tinggi) {
	if(l == r) {
		node* ret;
		ret = new node();
		ret -> num = l;
		return ret;
	}
	int maks, bts;
	maks = ((1 << (tinggi-1)) - 1);
	bts = r - maks + 1;
	if(bts <= l) {
		bts = l + 1;
	}
	node* ret;
	ret = new node();
	ret -> num = bts - 1;
	if(bts > l + 1) {
		ret -> kiri = bikin(l, bts - 2, tinggi-1);
	} else {
		ret -> kiri == NULL;
	}
	ret -> kanan = bikin(bts, r, tinggi - 1);
	return ret;
}

int getN(node* skrg) {
	if(skrg -> num == NULL) {
		return -1;
	} else {
		return skrg->num;
	}
}

void tulis(node* skrg) {
//	printf("%d %d\n", getN(skrg), getN(atas));
	if(getN(skrg) == temp) {
		printf("%d", skrg -> num);
	} else {
		printf(" %d", skrg -> num);
	}
	if(skrg -> kiri == NULL && skrg -> kanan == NULL) {
		return;
	}
	if(skrg -> kiri != NULL) {
		tulis(skrg -> kiri);
	}
	tulis(skrg -> kanan);
	return;
}

int main() {
	scanf("%d%d", &n, &h);
	if(n > (1 << (h))-1) {
		printf("tidak ada\n");
		return 0;
	}
	node* atas;
	atas = bikin(1, n, h);
	temp = getN(atas);
	tulis(atas);
	printf("\n");
	return 0;
}
