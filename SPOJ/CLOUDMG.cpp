#include <cstdio>
#include <algorithm>
#include <assert.h>
#include <vector>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int> 
#define ppi pair<pii, int> 

using namespace std;

vector <ppi> v;
int n, l, dp[2005][2005], aaa, bbb;
pii list[2005];

#define getchar_unlocked() getchar()
inline int baca() {
	int temp = 0;
	char c;
	c = getchar_unlocked();
	while(c < '0' || c > '9') {
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9') {
		temp *= 10;
		temp += c - '0';
		c = getchar_unlocked();
	}
	return temp;
}

bool cmp(pii a, pii b) {
	if(a.fs < b.fs) {
		return true;
	} else if(a.fs > b.fs) {
		return false;
	} else {
		return a.sc > b.sc;
	}
}

double ptg(pii a, pii b) {
	double aa;
	aa = a.sc - b.sc;
	aa /= b.fs - a.fs;
	return aa;
}

void insert(int mm, int cc, int idx) {
	pii c = mp(mm, cc);
	while(v.size() >= 2) {
		pii a, b;
		a = v[v.size()-2].fs;
		b = v[v.size()-1].fs;
		if(ptg(a, b) > ptg(b, c)) {
			v.pop_back();
		} else {
			break;
		}
	}
	v.push_back(mp(c, idx));
	return;
}

int binser(int x) {
	int l = 0, r = v.size()-1, mid;
	double zzz = x;
	int ctr = 3000;
	while(l < r) {
		assert(ctr--);
		mid = (l + r + 1) >> 1;
		pii a, b;
		a = v[mid - 1].fs;
		b = v[mid].fs;
		if(ptg(a, b) < zzz) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return v[l].sc;
}

int main() {
//	int lol = 1000;
	while(true) {
//		scanf("%d%d", &n, &l);
		n = baca();
		l = baca();
//		assert(lol--);
		if(n == 0 && l == 0){
			return 0;
		}
		for(int i = 1; i <= n; i++) {
//			scanf("%d%d", &aaa, &bbb);
			aaa = baca();
			bbb = baca();
			list[i] = mp(aaa, bbb);
		}
		sort(list+1, list+1+n, cmp);
		for(int i = 1; i <= n; i++) {
			dp[1][i] = list[i].sc * i;
		}
		for(int k = 2; k <= l; k++) {
			v.clear();
			for(int i = 1; i <= n; i++) {
				insert(-i, dp[k-1][i-1], i);
				int temp = binser(list[i].sc);
				dp[k][i] = dp[k-1][temp-1] + (i - temp + 1) * list[i].sc;
			}
		}
		printf("%d\n", dp[l][n]);
	}
	return 0;
}
