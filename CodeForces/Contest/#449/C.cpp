#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>

#define maks 2LL * 1e18

using namespace std;

int fp(int x) {
	if(x >= 60) {
		return maks;
	}
	long long prr = 1LL << x;
	ret = (pa + pb + pc) * (prr - 1) + prr * ps;
	if(ret < 0) {
		ret = maks;
	}
	return ret;
}

char f(int x, int ke) {
	if(x == 0) {
		if(ke > ps) {
			return '.';
		} else {
			return s[ke - 1];
		}
	}
	if(x == -1) {
		if(ke > pa) {
			return '.';
		} else {
			return a[ke - 1];
		}
	}
	if(x == -2) {
		if(ke > pb) {
			return '.';
		} else {
			return b[ke - 1];
		}
	}
	if(x == -3) {
		if(ke > pc) {
			return '.';
		} else {
			return c[ke - 1];
		}
	}
	tmp = fp(ke - 1);

}

int main() {
	for(int i = 1; i <= 100000; i++) {
		pjg[i] = -1;
	}
	s = "What are you doing at the end of the world? Are you busy? Will you save us?";
	a = "What are you doing while sending \"";
	b = "\"? Are you busy? Will you send \"";
	c = "\"?"
	ps = strlen(s);
	pa = strlen(a);
	pb = strlen(b);
	pc = strlen(c);
	scanf("%d", &q);
	while(q--) {
		scanf("%d%d", &n, &k);
		f(n, k);
	}
	return 0;
}