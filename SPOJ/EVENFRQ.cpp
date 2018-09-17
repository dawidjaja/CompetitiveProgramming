#include <algorithm>
#include <cstdio>

#define getchar() getchar_unlocked()

using namespace std;

long long vis[5000000], tog[5000000], itung, list[100005], n, a, q, x, k, l, r, tc, angka;
long long ps[100005];

long long hashing(long long a) {
	if(vis[a] == 0) {
		vis[a] = angka;
		tog[a] = 1;
		angka *= 3;
		return vis[a];
	} else {
		tog[a] *= -1;
		return tog[a] * vis[a];
	}
}

inline void bikinps() {
	itung = 0;
	ps[0] = hashing(list[0]);
	for(long long i = 1; i < n; i++) {
		ps[i] = ps[i-1] + hashing(list[i]);
	}
}
inline long long baca() {
	long long temp = 0;
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

inline void tulis() {
	printf("pres --> ");
	for(long long i = 0; i < n; i++) {
		printf("%lld ", ps[i]);
	}
	printf(" --\n");
}

int main() {
//	scanf("%lld", &tc);
	tc = baca();
	angka = 1;
	for(long long ii = 1; ii <= tc; ii++) {
		printf("Case %lld:\n", ii);
//		scanf("%lld%lld", &n, &q);
		n = baca();
		q = baca();
		for(long long i = 0; i < n; i++) {
//			scanf("%lld", &list[i]);
			list[i] = baca();
		}
		bikinps();
		while(q--) {
//			scanf("%lld", &a);
			a = baca();
//			tulis();
			if(a == 0) {
//				scanf("%lld%lld", &x, &k);
				x = baca();
				k = baca();
				x--;
				list[x] += k;
				bikinps();
			} else if(a == 1) {
//				scanf("%lld%lld%lld", &l, &r, &k);
				l = baca();
				r = baca();
				k = baca();
				l--; r--;
				for(long long i = l; i <= r; i++) {
					list[i] = k;
				}
				bikinps();
			} else if(a == 2) {
//				scanf("%lld%lld", &l, &r);
				l = baca();
				r = baca();
				l--; r--;
				if(ps[r] - ps[l-1] == 0) {
					printf("Yes\n");
				} else {
					printf("No\n");
				}
			}
//			bikinps();
		}
	}
	return 0;
}
