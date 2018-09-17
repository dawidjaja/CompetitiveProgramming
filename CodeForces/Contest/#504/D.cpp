#include <algorithm>
#include <cstdio>

using namespace std;

struct node {
	node* l;
	node* r;
	int val;
};

node* root[200005];
int freq[200005], seg[200005][2], n, q, list[200005], sisa;

node* create_node(node* ki, node* ka, int x) {
	node* ret = new node();
	ret->l = ki;
	ret->r = ka;
	ret->val = x;
	return (ret);
}

int getVal(node* now) {
	if (now == NULL) return 0;
	return now->val;
}

node* construct(int ki, int ka) {
	node* ret = new node();
	if (ki == ka) {
		ret = create_node(NULL, NULL, freq[ki]);
		return ret;
	}
	int mid = (ki + ka) >> 1;
	ret->l = construct(ki, mid);
	ret->r = construct(mid + 1, ka);
	ret->val = getVal(ret->l) + getVal(ret->r);
	return (ret);
}

node* update(node* base, int ki, int ka, int x) {
	// printf("-- update %d %d %d\n", ki, ka, x);
	node* ret = new node();
	if (ki == ka) {
		ret = create_node(NULL, NULL, freq[ki]);
		return (ret);
	}
	int mid = (ki + ka) >> 1;
	if (x <= mid) {
		ret->l = update(base->l, ki, mid, x);
		ret->r = base->r;
	} else {
		ret->l = base->l;
		ret->r = update(base->r, mid + 1, ka, x);
	}
	ret->val = getVal(ret->l) + getVal(ret->r);
	return (ret);
}

int query(node* ln, node* rn, int ki, int ka, int lq, int rq) {
	// printf("-- query %d %d %d %d\n", ki, ka, lq, rq);
	if (rq < lq) {
		return 0;
	}
	if (rq < ki || ka < lq) {
		return 0;
	}
	if (lq <= ki && ka <= rq) {
		return getVal(rn) - getVal(ln);
	}
	// printf("itung\n");
	int mid = (ki + ka) >> 1;
	int ret = 0;
	ret += query(ln->l, rn->l, ki, mid, lq, rq);
	ret += query(ln->r, rn->r, mid + 1, ka, lq, rq);
	return (ret);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= q; i++) {
		seg[i][0] = -1;
		seg[i][1] = -1;
	}
	root[0] = construct(1, q);
	// printf("selesai construct\n");
	for (int i = 1; i <= n; i++) {
		// printf("%d\n", i);
		scanf("%d", &list[i]);
		freq[list[i]]++;
		if (seg[list[i]][0] == -1) {
			seg[list[i]][0] = i;
		}
		seg[list[i]][1] = i;
		root[i] = update(root[i - 1], 1, q, list[i]);
	}
	// printf("selesai update\n");
	// for (int i = 1; i <= q; i++) {
	// 	printf("%d --> %d %d %d\n", i, seg[i][0], seg[i][1], getVal(root[i]));
	// }
	int cek = 1;
	for (int i = q; i >= 1; i--) {
		if (seg[i][0] != -1) {
			int tmp = query(root[seg[i][0] - 1], root[seg[i][1]], 1, q, 1, i - 1);
			if (tmp != 0) {
				// printf("-- %d %d \n", i, tmp);
				cek = 0;
				break;
			}
		}
	}
	if (cek) {
		if (freq[q] == 0) {
			if (freq[0] == 0) {
				printf("NO\n");
				return 0;
			}
			sisa = 1;
		} else {
			sisa = 0;
		}
		printf("YES\n");
		for (int i = 1; i <= n; i++) {
			if (list[i] == 0 && sisa) {
				list[i] = q;
				sisa = 0;
			} else if(list[i] == 0) {
				if (i == 1) {
					int tt = 1;
					while (list[tt] == 0) {
						tt++;
					}
					list[i] = list[tt];
				} else {
					list[i] = list[i - 1];
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (i == n) {
				printf("%d\n", list[i]);
			} else {
				printf("%d ", list[i]);
			}
		}
	} else {
		printf("NO\n");
	}
	return 0;
}