#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define fs first
#define sc second
#define mp make_pair
#define MAX 200005
#define INF 1e9

using namespace std;

int p[100005],es[100005],te[100005],nol[100005],ss[100005],ts[100005],n,m,s,t,a,b,c,temp,dr,cek,ansa,ansb;
pair<pair<int,int>,int> jln[200005];
vector <int> v[100005],mst,st,ga;
vector <pair<int,int> > ed[100005];

int par(int x){
	
	if(p[x]==x)
		return x;
	
	p[x]=par(p[x]);
	return p[x];
}

void dfss(int skrg,int sblm) {
	es[skrg] = sblm;
//	printf("es --> %d %d --\n", skrg, sblm);
	for(int i = 0; i < v[skrg].size(); i++){
		if(v[skrg][i] != sblm) {
			dfss(v[skrg][i], skrg);
		}
	}
	return;
}

void dfst(int skrg,int sblm) {
	te[skrg] = sblm;
//	printf("te --> %d %d --\n", skrg, sblm);
	for(int i = 0; i < v[skrg].size(); i++){
		if(v[skrg][i] != sblm) {
			dfst(v[skrg][i], skrg);
		}
	}
	return;
}

void dfs(int ,int sblm) {
	nol[skrg] = sblm;
	for(int i = 0; i < v[skrg].size(); i++){
		if(v[skrg][i] != sblm) {
			dfs0(v[skrg][i], skrg);
		}
	}
	return;
}

bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b) {
//	return tie(a.sc, a.fs.fs, a.fs.sc) < tie(b.sc, b.fs.fs, b.fs.sc);
	if(a.sc < b.sc) return true;
	if(a.sc > b.sc) return false;
	if(a.fs.fs < b.fs.fs) return true;
	if(a.fs.fs > b.fs.fs) return false;
	if(a.fs.sc < b.fs.sc) return true;
	return false;
}

inline void sssps() {
	priority_queue <pair<int, int> > pq;
	pq.push(mp(0,s));
	while(pq.size()) {
		int jrk, skrg;
		jrk = -pq.top().fs;
		skrg = pq.top().sc;
		pq.pop();
		if(jrk < ss[skrg]) {
			ss[skrg] = jrk;
			for(int i = 0; i < ed[skrg].size(); i++ ) {
				if(jrk + ed[skrg][i].sc < ss[ed[skrg][i].fs]) {
					pq.push(mp(-(jrk + ed[skrg][i].sc), ed[skrg][i].fs));
				}
			}
		}
	}
}

inline void ssspt() {
	priority_queue <pair<int, int> > pq;
	pq.push(mp(0,t));
	while(pq.size()) {
		int jrk, skrg;
		jrk = -pq.top().fs;
		skrg = pq.top().sc;
		pq.pop();
		if(jrk < ts[skrg]) {
			ts[skrg] = jrk;
			for(int i = 0; i < ed[skrg].size(); i++ ){
				if(jrk + ed[skrg][i].sc < ts[ed[skrg][i].fs]) {
					pq.push(mp(-(jrk + ed[skrg][i].sc), ed[skrg][i].fs));
				}
			}
		}
	}
}
int main ()
{
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for(int i = 0; i < m; i++ ) {
		scanf("%d%d%d", &a, &b, &c);
		jln[i] = mp(mp(min(a, b), max(a, b)), c);
		ed[a].push_back(mp(b, c));
		ed[b].push_back(mp(a, c));
	}

	for(int i = 0; i < n; i++) {
		ss[i] = INF;
		ts[i] = INF;
	}
	
	sssps();
	ssspt();
	
	sort(jln, jln+m, cmp);

	for(int i = 0; i < n; i++ ) {
		p[i]=i;
	}
	
	for(int i = 0 ; i < m ; i++ ) {
		if(par(jln[i].fs.fs) != par(jln[i].fs.sc)) {
			p[par(jln[i].fs.sc)] = par(jln[i].fs.fs);
			mst.push_back(i);
		}
	}
	
	for(int i = 0; i < mst.size(); i++) {
		v[jln[mst[i]].fs.fs].push_back(jln[mst[i]].fs.sc);
		v[jln[mst[i]].fs.sc].push_back(jln[mst[i]].fs.fs);
//		printf("-- %d %d %d %d--\n", mst[i], jln[mst[i]].fs.fs, jln[mst[i]].fs.sc, jln[mst[i]].sc);
	}
	
	temp = jln[mst.back()].sc;
//	printf("-- %d --\n",temp);	
	for(int i = mst.size()-1; i >= 0; i--){
		if(jln[mst[i]].sc != temp) {
			dr = i+1;
			break;
		}
	}
//	printf("%d -- %d\n",dr,mst.size()-1);
	
//	if(dr == mst.size()-1) {
//		printf("%d %d\n", jln[mst.back()].fs.fs, jln[mst.back()].fs.sc);
//		return 0;
//	}
	
	dfss(s, -1);
	dfst(t, -1);
	for(int i = 0; i < n; i++) {
		dfs(i, -1, i);
	}
	
	cek = 0;
	for(int i = dr; i < mst.size(); i++) {
		int x, y, z;
		x = jln[mst[i]].fs.fs;
		y = jln[mst[i]].fs.sc;
		z = jln[mst[i]].sc;
		if((es[x] == y && te[y] == x) || (es[y] == x && te[x] == y)) {
			cek = 1;
//			printf("--- %d --> %d %d & %d --> %d %d ---\n", x, es[x], te[x], y, es[y], te[y]);
		}
	}
	
	if(cek) {
		printf("%d %d\n", min(s,t), max(s,t));
	} else {
//		temp = MAX;
		for(int i = dr; i < mst.size(); i++) {
//			int x, y;
//			x = jln[mst[i]].fs.fs;
//			y = jln[mst[i]].fs.sc;
//			if(nol[x]==y) {
//				temp = min(temp,x);
//			} else {
//				temp = min(temp,y);
//			}
		}
		printf("0 %d\n", temp);
	}
	return 0;
}
