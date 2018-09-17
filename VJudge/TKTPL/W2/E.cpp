#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

int n, s, t, c, a, b, d, tmp, ans, ctr, awal[105][105], cap[105][105], flow[105], cek[105], asal[105];

bool SPFA() {
	// printf("spfa\n");
	queue <int> q;
	q.push(s);
	for(int i = 1; i <= n; i++) {
		cek[i] = 0;
		asal[i] = 0;
		flow[i] = 0;
	}
	cek[s] = 1;
	while(q.size()) {
		int skrg = q.front();
		// printf("%d\n", skrg);
		q.pop();
		for(int i = 1; i <= n; i++) {
			if(cek[i] == 0 && (cap[skrg][i] != 0 ||
			awal[min(skrg, i)][max(skrg, i)] != 0)) {
				// printf("%d - %d => %d %d \n", skrg, i, cap[skrg][i], awal[min(skrg, i)][max(skrg, i)]);
				cek[i] = 1;
				q.push(i);
				asal[i] = skrg;
				if(cap[skrg][i]) {
					flow[i] = cap[skrg][i];
				} else {
					flow[i] = awal[min(skrg, i)][max(skrg, i)];
				}
				if(i == t) {
					break;
				}
			}
		}
	}
	// printf("selesai %d\n", cek[t]);
	if(cek[t] == 0) {
		// printf("salah\n");
		return false;
	}
	int a, b;
	a = asal[t];
	b = t;
	tmp = flow[b];
	while(b != s) {
		tmp = min(flow[b], tmp);
		// printf("-- %d - %d --> %d\n", a, b, tmp);
		b = a;
		a = asal[b];
	}
	a = asal[t];
	b = t;
	// printf("-- %d --\n", b);
	while(b != s) {
		if(awal[min(a, b)][max(a, b)] >= tmp) {
			// printf("awal");
			awal[min(a, b)][max(a, b)] -= tmp;
		} else {
			// printf("cap");
			cap[a][b] -= tmp;
		}
		cap[b][a] += tmp;
		// printf("-- %d --\n", a);
		b = a;
		a = asal[b];
	}
	// printf("%d\n", tmp);
	// printf("bener\n");
	return true;
}

int main() {
	scanf("%d", &n);
	while(n != 0) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				awal[i][j] = 0;
				cap[i][j] = 0;
			}
		}
		ans = 0;
		ctr++;

		scanf("%d%d%d", &s, &t, &c);

		for(int i = 1; i <= c; i++) {
			scanf("%d%d%d", &a, &b, &d);
			// printf(" -- %d -- \n", i);
			if(a > b) {
				swap(a, b);
			}
			awal[a][b] += d;
		}
		// printf("qwer");
		while(SPFA()) {
			// printf("asdf");
			ans += tmp;
		}
		printf("Network %d\n", ctr);
		printf("The bandwidth is %d.\n", ans);
		printf("\n");
		scanf("%d", &n);
	}
	return 0;
}