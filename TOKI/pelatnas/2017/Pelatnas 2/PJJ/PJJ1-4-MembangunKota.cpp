#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int>

using namespace std;
int n,r,c,cek[1005][1005],a[10],b[10],vis[1005][1005],ans,p[100005];
map <int,int> ud[100005];
pair<int,int> list[1005][1005];
vector <pair<int,int> > kota;
vector <pair<int, pii> > v;
queue <pair<pii,pii> > q;

bool masuk(int y,int x, int i) {
	if((y+a[i] >= 0) && (y+a[i] < 1000) && (x+b[i] >= 0) && (x+b[i] < 1000)) {
		return true;
	}
	return false;
}

int par(int x) {
	if(p[x] == x) {
		return x;
	}
	p[x] = par(p[x]);
	return p[x];
}

int main () {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d",&r,&c);
		kota.push_back(mp(r,c));
//		printf("--- %d %d ---\n",kota[kota.size()-1].fs,kota[kota.size()-1].sc);
	}
	sort(kota.begin(),kota.end());
	kota.erase(unique(kota.begin(),kota.end()),kota.end());
//	printf("--- %d ---\n",kota.size());
//	for(int i = 0; i < kota.size(); i++) {
//		printf("-- %d %d --\n", kota[i].fs, kota[i].sc);
//	}
	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < 1000; j++) {
			list[i][j] = mp(100001,0);
		}
	}
	for(int i = 0; i < kota.size(); i++) {
		q.push(mp(mp(i,0),kota[i]));
		list[kota[i].fs][kota[i].sc] = mp(i,0);
		p[i] = i;
	}
	a[1] = b[2] = 1;
	a[3] = b[4] = -1;
	while(q.size()) {
		int y,x,s,skrg;
		skrg = q.front().fs.fs;
		s = q.front().fs.sc;
		y = q.front().sc.fs;
		x = q.front().sc.sc;
		q.pop();
		for(int i = 1; i <= 4; i++) {
			if(masuk(y,x,i)) {
				if(list[y+a[i]][x+b[i]].fs == 100001) {
					list[y+a[i]][x+b[i]] = mp(skrg,s+1);
					q.push(mp(mp(skrg,s+1),mp(y+a[i],x+b[i])));
				} else {
					pair<int,int> temp;
					temp = list[y+a[i]][x+b[i]];
					if(temp.fs != skrg) {
						if(!ud[temp.fs].count(skrg)) {
							ud[temp.fs][skrg] = 1;
							ud[skrg][temp.fs] = 1;
							v.push_back(mp(s+1+temp.sc,mp(skrg,temp.fs)));
//							v[temp.fs].push_back(mp(skrg,s+1+temp.sc));
//							v[skrg].push_back(mp(temp.fs,s+1+temp.sc));
						}
					}
				}
			}
		}
	}
//	for(int i = 0; i < kota.size(); i++ ) {
//		printf("--- %d - %d %d --> \n",i,kota[i].fs,kota[i].sc);
//		for(int j = 0; j < v[i].size(); j++) {
//			printf("   --- %d --> %d %d , %d ---\n",v[i][j].fs, kota[v[i][j].fs].fs, kota[v[i][j].fs].sc, v[i][j].sc);
//		}
//	}
	sort(v.begin(), v.end());
	ans = 0;
	for(int i = 0; i < v.size(); i++) {
		int q,w;
		q = par(v[i].sc.fs);
		w = par(v[i].sc.sc);
		if(q != w) {
			p[q] = w;
			ans += v[i].fs;
		}
	}
	printf("%d\n",ans);
	return 0;
}
