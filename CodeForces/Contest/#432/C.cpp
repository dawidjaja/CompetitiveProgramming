#include <algorithm>
#include <cstdio>
#include <cmath>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>
#define ppp pair<pii,pii>
#define ppi pair<ppp,int>

#define PI 3.14159265

using namespace std;

ppi list[1005];
int n, cek;

ppi krg(int a, int b) {
	int v, w, x, y, z;
	v = list[a].fs.fs.fs - list[b].fs.fs.fs;
	w = list[a].fs.fs.sc - list[b].fs.fs.sc;
	x = list[a].fs.sc.fs - list[b].fs.sc.fs;
	y = list[a].fs.sc.sc - list[b].fs.sc.sc;
	z = list[a].sc - list[b].sc;
	return mp(mp(mp(v, w), mp(x, y)), z);
}

double dot(ppi a, ppi b) {
	int v, w, x, y, z, ret;
	ret = a.fs.fs.fs * b.fs.fs.fs;
	ret += a.fs.fs.sc * b.fs.fs.sc;
	ret += a.fs.sc.fs * b.fs.sc.fs;
	ret += a.fs.sc.sc * b.fs.sc.sc;
	ret += a.sc * b.sc;
	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d%d%d", &list[i].fs.fs.fs, &list[i].fs.fs.sc, &list[i].fs.sc.fs, &list[i].fs.sc.sc, &list[i].sc);
	}
	if(n < 3) {
		printf("%d\n", n);
		for(int i = 1; i <= n; i++) {
			printf("%d\n", i);
		}
	} else {
		for(int i = 1; i <= n; i++) {
			cek = i;
			for(int j = 1; j <= n; j++) {
				if(i != j) {
					for(int k = 1; k <= n; k++) {
						if(j != k && i != k) {
							ppi ta, tb;
							ta = krg(k, i);
							tb = krg(j, i);
							if(acos(dot(ta, tb) / (sqrt(dot(ta, ta) * dot(tb, tb)))) < PI / 2) {
								cek = 0;
								break;
							}
						}
					}
				}
				if(cek == 0) {
					break;
				}
			}
			if(cek == i) {
				printf("1\n");
				printf("%d\n", cek);
				return 0;
			}
		}
		printf("0\n");
	}
	return 0;
}