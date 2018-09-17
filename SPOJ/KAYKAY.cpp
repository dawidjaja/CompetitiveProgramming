#include <algorithm>
#include <cstdio>

using namespace std;

void bikin(int skrg) {
	l[srkg] = -1;
	r[skrg] = -1;
	sblm = -1;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(l[skrg] == -1) {
			l[skrg] = v[skrg][i];
		}
		if(sblm != -1) {
			kanan[sblm] = v[skrg][i];
		}
		bikin(v[skrg][i]);
		sblm = v[skrg][i];
	}
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d%d", &n, &a, &b);
		for(int i = 0; i < n; i++) {
			scanf("%d", &list[i]);
			v[i].clear();
		}
		for(int i = 1; i < n; i++) {
			scanf("%d%d", &s, &t);
			v[s].push_back(t);
		}
		bikin(0, -1);
	}
	return 0;
}
