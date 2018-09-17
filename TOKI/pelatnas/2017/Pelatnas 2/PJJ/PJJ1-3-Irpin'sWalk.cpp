#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <cmath>

#define INF 3223372036854775807
#define fs first
#define sc second
#define mp make_pair

using namespace std;
long long t, n, m, s, a, b, w, list[10005][55], ans, tt;
bool vis[10005][55];
vector <pair<long long,long long> > v[10005];
priority_queue <pair<pair<long long,long long> , long long> > pq;

int main () {
	scanf("%lld", &tt);
	for(long long _ = 1; _ <= tt; _++) {
		scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
		
		for(long long i = 0; i <= n; i++) {
			v[i].clear();
		}
		while(pq.size()) {
			pq.pop();
		}
		
		for(long long i = 0; i < m; i++) {
			scanf("%lld%lld%lld", &a,&b,&w);
			v[a].push_back(mp(b,w));
			v[b].push_back(mp(a,w));
		}
		
		for(long long i = 0; i <= n; i++) {
			for(long long j = 0; j <= 50; j++) {
				list[i][j] = INF;
				vis[i][j] = true;
			}
		}
		
		pq.push(mp(mp(0,0),s));
		
		while(pq.size()) {
			long long jrk, r, skrg;
			jrk = -pq.top().fs.fs;
			r = pq.top().fs.sc;
			skrg = pq.top().sc;
//			printf("-- %lld %lld %lld --\n", jrk, r, skrg);
			pq.pop();
			if(jrk <= list[skrg][r]) {
				list[skrg][r] = jrk;
				for(long long i = 0; i < v[skrg].size(); i++) {
					if(jrk + v[skrg][i].sc < list[v[skrg][i].fs][r+1]) {
						list[v[skrg][i].fs][r+1] = jrk + v[skrg][i].sc;
						pq.push(mp(mp(-(jrk + v[skrg][i].sc),r+1),v[skrg][i].fs));
					}
				}
			}
		}
		
		ans = INF;
		for(long long i = 0; i <= 50; i++) {
			long long temp;
			temp = (1 << i);
			if(temp <= list[t][i]) {
				ans = min(ans,list[t][i]*2);
			} else {
				ans = min(ans,list[t][i]);
			}
		}
		
		if(ans == INF) {
			printf("Case #%lld: -1\n", _);
		} else {
			printf("Case #%lld: %lld\n", _, ans);
		}
	}
	return 0;
}
