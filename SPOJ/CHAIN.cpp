#include <algorithm>
#include <cstdio>
#include <vector>

// #define getchar_unlocked getchar

using namespace std;

int p[50005], lvl[50005], t, n, k, d, a, b, ans;
vector <int> v[50005];

inline int baca() {
	int temp = 0, kali = 1;
	char c;
	c = getchar_unlocked();
	while((c < '0' || c > '9') && c != '-') {
		c = getchar_unlocked();
	}
	while((c >= '0' && c <= '9') || c == '-') {
		if(c == '-') {
			kali = -1;
			c = getchar_unlocked();
			continue;
		}
		temp = (temp << 3) + (temp << 1);
		temp += c - '0';
		c = getchar_unlocked();
	}
	temp *= kali;
	return temp;
}

int par(int x) {
	if(p[x] == x) {
		return x;
	} else {
		p[x] = par(p[x]);
		return p[x];
	}
}

bool cek(int kon, int x, int y) {
	if(par(x) == par(y)) {
		//dah tau
		if(kon == 1) {
			if(lvl[x] == lvl[y]) {
				return false;
			} else {
				return true;
			}
		} else {
			if(((lvl[x] + 1) % 3) == lvl[y]) {
				return false;
			} else {
				return true;
			}
		}
	} else {
		//blom tau
		if(kon == 1) {
			if(v[par(x)].size() >= v[par(y)].size()) {
				// y -> x
				for(int i = 0; i < v[par(y)].size(); i++) {
					if(v[par(y)][i] != y) {
						lvl[v[par(y)][i]] += lvl[x] - lvl[y] + 3;
						lvl[v[par(y)][i]] %= 3;
						v[par(x)].push_back(v[par(y)][i]);
					}
				}
				p[par(y)] = par(x);
				lvl[y] = lvl[x];
				v[par(x)].push_back(y);
			} else {
				// x -> y
				for(int i = 0; i < v[par(x)].size(); i++) {
					if(v[par(x)][i] != x) {
						lvl[v[par(x)][i]] += lvl[y] - lvl[x] + 3;
						lvl[v[par(x)][i]] %= 3;
						v[par(y)].push_back(v[par(x)][i]);
					}
				}
				p[par(x)] = par(y);
				lvl[x] = lvl[y];
				v[par(y)].push_back(x);
			}
		} else if(kon == 2) {
			if(v[par(x)].size() >= v[par(y)].size()) {
				// y -> x
				for(int i = 0; i < v[par(y)].size(); i++) {
					if(v[par(y)][i] != y) {
						lvl[v[par(y)][i]] += lvl[x] - lvl[y] + 4;
						lvl[v[par(y)][i]] %= 3;
						v[par(x)].push_back(v[par(y)][i]);
					}
				}
				p[par(y)] = par(x);
				lvl[y] = (lvl[x] + 1) % 3;
				v[par(x)].push_back(y);
			} else {
				// x -> y
				for(int i = 0; i < v[par(x)].size(); i++) {
					if(v[par(x)][i] != x) {
						lvl[v[par(x)][i]] += lvl[y] - lvl[x] + 5;
						lvl[v[par(x)][i]] %= 3;
						v[par(y)].push_back(v[par(x)][i]);
					}
				}
				lvl[x] = (lvl[y] + 2) % 3;
				v[par(y)].push_back(x);
				p[par(x)] = par(y);
			}
		}
		return false;
	}
}

int main() {
	// scanf("%d", &t);
	t = baca();
	while(t--) {
		// scanf("%d%d", &n, &k);
		n = baca();
		k = baca();
		ans = 0;
		for(int i = 1; i <= n; i++) {
			v[i].clear();
			v[i].push_back(i);
			p[i] = i;
			lvl[i] = 0;
		}
		while(k--) {
			// scanf("%d%d%d", &d, &a, &b);
			d = baca();
			a = baca();
			b = baca();
			if ((a > n || b > n) || (d == 2 && a == b)) {
				ans++;
			} else if(cek(d, a, b)) {
				ans++;
			}
			// for(int i = 1; i <= 10; i++) {
			// 	printf("%d --> %d %d\n", i, par(i), lvl[i]);
			// }
			// printf("-- %d --\n", ans);
		}
		printf("%d\n", ans);
	}
	return 0;
}