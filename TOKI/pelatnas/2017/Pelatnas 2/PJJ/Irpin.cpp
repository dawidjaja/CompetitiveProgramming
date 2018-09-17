#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long,long long> 
#define INF (1LL << 31)

using namespace std;

vector <pii> v[10005];
long long list[10005][35], vis[10005][35],tc,n,m,s,t,a,b,w, ans;
priority_queue <pair<pii,long long> > pq;

inline void reset() {
	for(long long i = 0; i <= 10000; i++) {
		v[i].clear();
		for(long long j = 0; j <= 30; j++) {
			list[i][j] = (1LL << 31);
			vis[i][j] = 0;
		}
	}
}

int main () {
	scanf("%lld", &tc);
	for(long long _ = 1; _ <= tc; _++) {
		scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
		
		reset();
		
		for(long long i = 1; i <= m; i++) {
			scanf("%lld%lld%lld", &a, &b, &w);
			v[a].push_back(mp(b,w));
			v[b].push_back(mp(a,w));
		}
		
		pq.push(mp(mp(0,0),s));
		while(pq.size()) {
			long long jrk,r,skrg;
			jrk = -pq.top().fs.fs;
			r = pq.top().fs.sc;
			skrg = pq.top().sc;
			pq.pop();
			if(!vis[skrg][r]) {
				vis[skrg][r] = 1;
				for(long long i = 0; i < v[skrg].size(); i++) {
					if((!vis[v[skrg][i].fs][min(30LL,r+1)]) && ((jrk + v[skrg][i].sc) < list[v[skrg][i].fs][min(30LL,r+1)])) {
						pq.push(mp(mp(-(jrk + v[skrg][i].sc), min(30LL,r+1)), v[skrg][i].fs));
						list[v[skrg][i].fs][min(30LL,r+1)] = (jrk + v[skrg][i].sc);
					}
				}
			}
		}
		ans = (1LL << 31);
		for(long long i = 1; i <= 30; i++) {
//			printf("--- %lld %lld ---\n", (1LL << i), list[t][i]);
			if((1LL << i) <= list[t][i]) {
				ans = min(ans, list[t][i]*2);
			} else {
				ans = min(ans, list[t][i]);
			}
		}
		if(ans == (1LL << 31)) {
			ans = -1;
		}
		printf("Case #%lld: %lld\n", _, ans);
	}
	return 0;
}
