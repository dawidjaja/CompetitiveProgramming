#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <set>

using namespace std;

int dp[35][10005][17], e,n,c,l,g,x,ans, asdf[35][10005][17];
vector <int> v[10005];
set <int> suka[10005],tkt[10005];

int itung(int mask, int skrg) {
	int ret;
	ret = 0;
	for(int k = 0; k < v[skrg].size(); k++) {
		int anak;
		anak = v[skrg][k];
		for(int i = 0; i <= 4; i++) {
			int now;
			now = (skrg + i) % n;
			if(now == 0) {
				now = n;
			}
			if(mask & (1 << (4-i))) {
				if(suka[now].count(anak)) {
					ret++;
					break;
				}
			} else {
				if(tkt[now].count(anak)) {
					ret++;
					break;
				}
			}
		}
	}
	return ret; 
}

int f(int mask, int skrg,int dpn) {
	if(skrg == n) {
		return itung(mask,skrg);
	}
	
	if(dp[mask][skrg][dpn] != -1) {
		return dp[mask][skrg][dpn];
	}
	
	int ret;
	ret = 0;
	if(skrg+5 > n) {
		int dif;
		dif = skrg+5-n;
		int baru;
		baru = (mask & ((1 << 4)-1))*2;
		if(dpn & (1 << (4-dif))) {
			baru++;
		}
		ret = f(baru, skrg+1, dpn);
	} else {
		int nyala, mati;
		mati = (mask & ((1 << 4)-1))*2;
		nyala = mati+1;
		ret = max(f(nyala, skrg+1, dpn), f(mati, skrg+1, dpn));
	}
	ret += itung(mask, skrg);
	dp[mask][skrg][dpn] = ret;
	return ret;
}

int main () {
	scanf("%d%d", &n, &c);
	for(int i = 1; i <= c; i++) {
		scanf("%d%d%d",&e, &g, &l);
		v[e].push_back(i);
		for(int j = 1; j <= g; j++) {
			scanf("%d", &x);
			tkt[x].insert(i);
		}
		for(int j = 1; j <= l; j++) {
			scanf("%d", &x);
			suka[x].insert(i);
		}
	}

//	1<<1 1
//	1<<2 10
//	1<<3 100
//	1<<4 1000
//	1<<5 10000
//	1<<6 100000 --> 11111
	
	for(int i = 0; i < (1 << 5); i++) {
		for(int j = 0; j <= n+1; j++) {
			for(int k = 0; k < (1 << 4); k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	ans = 0;
	for(int i = 0; i < (1 << 5); i++) {
		ans = max(ans, f(i,1,i/2));
	}
	printf("%d\n",ans);
	return 0;
}
