#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>


#define fs first
#define sc second

using namespace std;

long long n, m, k;
string nama, trakhir, awal;
map <string, long long> vis;

struct soal {
	char c;
	long long a, t;
};

map <string, vector<soal> > tim;

inline bool cek(string sblm, string skrg) {
	long long ctra, ctrb, ta, tb, ga, gb;
	ctra = ctrb = ta = tb = ga = gb = 0;

	for(long long i = 0; i < n; i++) {
		if(tim[sblm][i].c == '+') {
			ctra++;
			ta += tim[sblm][i].t + 20 * (tim[sblm][i].a - 1);
			ga = max(ga, tim[sblm][i].t);
		}
		if(tim[skrg][i].c == '+') {
			ctrb++;
			tb += tim[skrg][i].t + 20 * (tim[skrg][i].a - 1);
			gb = max(gb, tim[skrg][i].t);
		}
	}
	if(ctra > ctrb) {
		return true;
	}
	if(ctra < ctrb) {
		return false;
	}
	if(ctra == ctrb) {
		if(ta < tb){
			return true;
		} 
		if(ta > tb){
			return false;
		}
		if(ta == tb) {
			if(ga < gb) {
				return true;
			}
			if(ga > gb) {
				return false;
			}
			return sblm < skrg;
		}
	}
}

inline void opt(string skrg) {
	for(long long i = 0; i < n; i++) {
		if(tim[skrg][i].c != '+') {
			tim[skrg][i].c = '+';
			tim[skrg][i].a++;
			tim[skrg][i].t = 240;
		}
	}
}

int main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	for(long long i = 1; i <= m; i++) {
		cin.ignore();
		cin >> nama;
		for(long long i = 1; i <= n; i++) {
			soal tmp;
			getchar();
			scanf("%c%lld%lld", &tmp.c, &tmp.a, &tmp.t);
			tim[nama].push_back(tmp);
		}
	}
	for(long long i = 1; i <= k; i++) {
		cin.ignore();
		cin >> nama;
		vis[nama] = 1;
		for(long long i = 0; i < n; i++) {
			soal tmp;
			getchar();
			scanf("%c%lld%lld", &tmp.c, &tmp.a, &tmp.t);
			// ganti(nama, i, tmp);
			tim[nama][i] = tmp;
		}
		if(i == 1) {
			awal = nama;
		}
		if(i == k) {
			trakhir = nama;
		}
	}
	for(auto it = tim.begin(); it != tim.end(); it++) {
		string ss = it->fs;
		if(vis[ss] == 0) {
			if(cek(ss, trakhir)) {
				opt(ss);
				if(cek(awal, ss)) {
					printf("Fake\n");
					return 0;
				}
			}
		}
	}
	printf("Leaked\n");
	return 0;
}