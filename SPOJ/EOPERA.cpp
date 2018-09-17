#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <queue>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int> 

using namespace std;

int t, akhir, y, x, jauh, cek, list[25], ans, awal, tes[20];
queue <pair<pair<long long,int> , pair<int, int> > > q;
map <long long, int> dpn, blkg;
vector <int> v[20], ve;
map <long long, vector<int> > debug;

inline long long ganti(long long x, int a, int b) {
	long long temp, aa, bb;
	temp = x;
	bb = pow(13, b);
	temp = temp % bb;
	aa = temp/pow(13, b-1);
	temp -= aa * pow(13, b-1);
	temp += aa * pow(13, a);
//	printf("%lld\n", temp);
	return temp;
}

void permut(int skrg, int hash) {
	if(skrg == 12) {
		debug[hash] = ve;
	}
	for(int i = 0; i <= 11; i++) {
		if(i <= 5) {
			for(int j = 0; j <= skrg; j++) {
				printf("  ");
			}
			printf("%d\n", i);
		}
		if(tes[i] == 0) {
			tes[i] = 1;
			ve.push_back(i);
			permut(skrg+1, hash*13 + i);
			tes[i] = 0;
			ve.pop_back();
		}
	}
}

int main () {
	scanf("%d", &t);
	int T = t;
	for(int i = 0; i <= 11; i++) {
		for(int j = i; j <= 11;j++) {
			int temp;
			temp = abs(i-j);
			if((temp == 1 && (i/3 == j/3)) || (temp == 3 && (i/6 == j/6)) || (temp == 6 && i/12 == j/12)){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
//	permut(0, 0);
	awal = 0;
	for(int i = 0 ; i <= 11; i++) {
		awal *= 13;
		awal += i;
	}
	y = 0;
	jauh = 0;
	dpn[awal] = 0;
	while(T--) {
		akhir = 0;
		cek = 1;
		for(int i = 0; i <= 11; i++) {
			scanf("%d", &list[i]);
			if(i != list[i]) {
				cek = 0;
			}
			akhir *= 13;
			akhir += list[i];
			if(list[i] == 0) {
				x = i;
			}
		}
		if(cek) {
			printf("0\n");
			continue;
		}
		ans = -1;
		blkg.clear();
		blkg[akhir] = 0;
		printf("%lld\n", akhir);
		while(q.size()) {
			q.pop();
		}
		q.push(mp(mp(awal, y), mp(0, 0)));
		q.push(mp(mp(akhir, x), mp(1, 0)));
		int aaaa = 20;
		while(q.size()) {
//			if(!aaaa--) {
//				break;
//			}
			pair<pair<long long, int> , pii> skrg;
			skrg = q.front();
			q.pop();
			for(int i = 0; i < debug[skrg.fs.fs].size(); i++) {
				printf("%d ", debug[skrg.fs.fs][i]);
			}
			printf("\n");
			printf("-- %d %d %d %d --\n", skrg.fs.fs, skrg.fs.sc, skrg.sc.fs, skrg.sc.sc);
			if(skrg.sc.fs) {
				//yg blkg
				long long temp;
				for(int i = 0; i < v[skrg.fs.sc].size(); i++) {
					temp = ganti(skrg.fs.fs, skrg.fs.sc, v[skrg.fs.sc][i]);
					if(!blkg.count(temp)) {
						if(dpn.count(temp)) {
							ans = dpn[temp] + skrg.sc.sc + 1;
							break;
						}
						blkg[temp] = skrg.sc.sc+1;
						q.push(mp(mp(temp, v[skrg.fs.sc][i]), mp(1, skrg.sc.sc+1)));
					}
				}
				if(ans != -1) {
					break;
				}
			} else {
				//yg dpn
				long long temp;
				for(int i = 0; i < v[skrg.fs.sc].size(); i++) {
					temp = ganti(skrg.fs.fs, skrg.fs.sc, v[skrg.fs.sc][i]);
					if(!dpn.count(temp)) {
						if(blkg.count(temp)) {
							ans = blkg[temp] + skrg.sc.sc + 1;
							break;
						}
						dpn[temp] = skrg.sc.sc+1;
						q.push(mp(mp(temp, v[skrg.fs.sc][i]), mp(0, skrg.sc.sc+1)));
					}
				}
				if(ans != -1) {
					break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
