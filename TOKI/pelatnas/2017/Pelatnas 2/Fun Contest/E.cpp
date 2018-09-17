#include <algorithm>
#include <cstdio>

using namespace std;

long long dlm[300005], p[300005][20], bin[300005][20], list[300005], n, ctr, kd, x, d, y, z, ans, ca;

long long LCA(long long x, long long y) {
	long long temp;
	if(dlm[x] > dlm[y]) {
		swap(x, y);
	}
	for(long long i = 19; i >= 0; i--) {
		if(p[y][i] != -1 && dlm[p[y][i]] >= dlm[x]) {
			y = p[y][i];
			temp ^= bin[y][i];
		}
	}
	if(x == y) {
		ca = x;
//		temp ^= list[x];
		return temp;
	}
	for(long long i = 19; i >= 0; i--) {
		if(p[y][i] != -1 && p[y][i] != p[x][i]) {
			y = p[y][i];
			x = p[x][i];
			temp ^= bin[y][i];
			temp ^= bin[x][i];
		}
	}
	temp ^= bin[y][0];
	ca = p[x][0];
	return temp;
}

int main() {
	scanf("%d", &n);
	ctr = 1;
	for(long long _ = 1; _ <= n; _++) {
		scanf("%lld", &kd);
		if(kd == 1) {
			scanf("%lld%lld", &x, &d);
			p[ctr][0] = x;
			if(x == -1) {
				dlm[ctr] = 0;
			} else {
				dlm[ctr] = dlm[x] + 1;
			}
			list[ctr] = 1 << d;
			bin[ctr][0] = list[x];
			for(long long i = 1; i <= 19; i++) {
				if(p[ctr][i-1] == -1) {
					for(long long j = i; j <= 19; j++) {
						p[ctr][j] = -1;
					}
					break;
				}
				p[ctr][i] = p[p[ctr][i-1]][i-1];
				bin[ctr][i] = bin[p[ctr][i-1]][i-1] ^ bin[ctr][i-1];
			}
			ctr++;
		} else if(kd == 2) {
			scanf("%lld", &x);
		} else if(kd == 3) {
			scanf("%lld%lld", &x, &y);
			z = LCA(x, y);
			z ^= list[x];
			z ^= list[y];
			ans =  __builtin_popcount(z);
			printf("%lld\n", ans);
		}
//		for(int i = 1; i <= ctr; i++) {
//			printf(" -- %d\n", i);
//			for(int j = 0; j <= 20; j++) {
//				printf("------ %d\n", p[i][j]);
//			}
//		}
	}
	return 0;
}
