#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

const int INF = INT_MAX;

int n, m, a, b, c, kcl[10005], freq[10005], s, t;
vector<pii> v[10005];
priority_queue <pii> pq;

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		v[a].push_back({b, c}); 
	}
	scanf("%d%d", &s, &t);

	for(int i = 0; i < n; ++i) {
		if(i == s) {
			kcl[i] = 0;
		} else {
			kcl[i] = INF;
		}
	}
	freq[s] = 1;
	pq.push({0, s});
	while(!pq.empty()) {
		int jrk = -pq.top().fs;
		int skrg = pq.top().sc;
		// int bnyk = pq.front().fs.sc;
		// printf(" -- %d %d\n", jrk, skrg);
		pq.pop();
		if(jrk == kcl[skrg]) {
			int vs = v[skrg].size();
			for(int i = 0; i < vs; ++i) {
				int ke = v[skrg][i].fs;
				int w = v[skrg][i].sc;
				if(jrk + w < kcl[ke]) {
					kcl[ke] = jrk + w;
					freq[ke] = freq[skrg];
					pq.push({-kcl[ke], ke});
				} else if(jrk + w == kcl[ke]) {
					freq[ke] += freq[skrg];
				}
			}
		}
	}
	// for(int i = 0; i < n; i++) {
	// 	printf("-- %d -> %d %d\n", i, kcl[i], freq[i]);
	// }
	printf("%d\n", freq[t]);
	return 0;
}