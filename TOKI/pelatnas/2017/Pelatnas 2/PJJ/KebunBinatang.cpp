#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

int dp[35][10005][17], e,n,c,l,g,x,ans, asdf[35][10005], suka[50005], tkt[50005];
vector <int> v[10005];

int itung(int mask, int skrg) {
	
//	if(asdf[mask][skrg] != -1) {
//		return asdf[mask][skrg];
//	}
	
	int ret;
	ret = 0;
	for(int i = 0; i < v[skrg].size(); i++) {
		int anak;
		anak = v[skrg][i];
		
		for(int j = 0; j <= 4; j++) {
			if(mask & (1 << j)) {
				if(suka[anak] & (1 << j)) {
					ret++;
					break;
				}
			} else {
				if(tkt[anak] & (1 << j)) {
					ret++;
					break;
				}
			}
		}
	}
//	asdf[mask][skrg] = ret;
	return ret;
}

int f(int mask, int skrg, int dpn) {
//	printf("-- %d %d %d--\n",mask, skrg, dpn);
	if(skrg == n) {
		return itung(mask,skrg);
	}
	if(dp[mask][skrg][dpn] != -1) {
		return dp[mask][skrg][dpn];
	}
	
	int ret;
	ret = 0;
	if(skrg + 5 > n) {
		int dif,baru;
		dif = skrg + 5 - n;
		baru = (((1<<4)-1) & mask)*2;
		if(dpn & (1<<(4-dif))) {
			baru++;
		}
		ret = f(baru, skrg+1, dpn);
		ret += itung(mask,skrg);
	} else {
		int nyala, mati;
		mati = (((1<<4)-1) & mask)*2;
		nyala = mati + 1;
		ret = max(f(mati, skrg+1, dpn), f(nyala, skrg+1, dpn));
		ret += itung(mask,skrg);
	}
	dp[mask][skrg][dpn] = ret;
	return ret;
}

inline void init() {
	
	for(int i = 0; i < (1 << 5); i++) {
		for(int j = 0; j <= 10000; j++) {
			for(int k = 0; k < (1 << 4); k++) {
				dp[i][j][k] = -1;
			}
//			asdf[i][j] = -1;
		}
	}
	ans = 0;
}

int main () {
	scanf("%d%d", &n, &c);
	for(int i = 1; i <= c; i++) {
		scanf("%d%d%d",&e, &g, &l);
		v[e].push_back(i);
		for(int j = 1; j <= g; j++) {
			scanf("%d", &x);
			int dif;
			dif = (x-e+n) % n;
			tkt[i] = tkt[i] | (1 << (4-dif));
		}
		for(int j = 1; j <= l; j++) {
			scanf("%d", &x);
			int dif;
			dif = (x-e+n) % n;
			suka[i] = suka[i] | (1 << (4-dif));
		}
//		printf("-- %d %d --\n",tkt[i],suka[i]);
	}
	
	init();

	for(int i = 0; i < (1 << 5); i++) {
		ans = max(ans, f(i, 1, i/2));
	}
	printf("%d\n",ans);
	return 0;
}
