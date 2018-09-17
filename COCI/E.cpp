#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;

pii kitas, kawah;

int cross(pii a, pii b, pii c) {
	pii d, e;
	d = mp(b.fs - a.fs, b.sc - a.sc);
	e = mp(c.fs - b.fs, b.sc - a.sc);
	int ret;
	ret = d.fs * e.sc - d.sc * e.fs;
	return ret;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &list[i].fs, &list[i].sc);
		if(list[i].fs >= 0 && list[i].sc >= 0) {
			if(list[i].sc >= kitas.sc) {
				if(list[i].sc == kitas.sc)
			}
		}
	}
	cek = 1;
	for(int i = 1; i <= n-2; i++) {
		if(cross(list[i], list[i + 1], list[i + 2]) != 0) {
			cek = 0;
		}
	}
	if(cek) {
		printf("-1\n");
		return 0;
	}

	return 0;
}