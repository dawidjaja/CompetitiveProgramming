#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define fs first
#define sc second 
#define mp make_pair
#define pii pair<int,int>
#define pip pair<int,pii>

using namespace std;

int n, vis[100005];
long long ans;
pip list[100005];
vector <pii> v[100005];
priority_queue <pii> pq;

bool cmpa(pip a, pip b) {
	return a.sc < b.sc;
}

bool cmpb(pip a, pip b) {
	return a.sc.sc < b.sc.sc;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &list[i].sc.fs, &list[i].sc.sc);
		list[i].fs = i;
		vis[i] = 0;
	}
	sort(list + 1, list + 1 + n, cmpa);
	for(int i = 1; i < n; i++) {
		v[list[i].fs].push_back(mp(list[i + 1].fs, list[i + 1].sc.fs - list[i].sc.fs));
		v[list[i + 1].fs].push_back(mp(list[i].fs, list[i + 1].sc.fs - list[i].sc.fs));
	}
	sort(list + 1, list + 1 + n, cmpb);
	for(int i = 1; i < n; i++) {
		v[list[i].fs].push_back(mp(list[i + 1].fs, list[i + 1].sc.sc - list[i].sc.sc));
		v[list[i + 1].fs].push_back(mp(list[i].fs, list[i + 1].sc.sc - list[i].sc.sc));
	}
	pq.push(mp(0, 1));
	ans = 0;
	while(pq.size()) {
		int skrg, jrk;
		jrk = -pq.top().fs;
		skrg = pq.top().sc;
		pq.pop();
		if(vis[skrg] == 1) {
			continue;
		} else {
			vis[skrg] = 1;
			ans += jrk;
			for(int i = 0; i < v[skrg].size(); i++) {
				if(vis[v[skrg][i].fs] == 0) {
					pq.push(mp(-v[skrg][i].sc, v[skrg][i].fs));
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}