#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>
#define ppi pair<pii, int> 
#define pip pair<int, pii>
#define INF 1e9

//#define getchar_unlocked() getchar()
using namespace std;
inline int baca() {
	int temp = 0;
	char c;
	c = getchar_unlocked();
	while(c < '0' || c > '9') {
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9') {
		temp *= 10;
		temp += c - '0';
		c = getchar_unlocked();
	}
	return temp;
}

int n, a, vis[2005], bnyk[2005], cek;
queue <pii> q;
vector <int> v[2005];

int main() {
//	scanf("%d", &n);
	n = baca();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
//			scanf("%d", &a);
			a = baca();
			if(a) {
				v[i].push_back(j);
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		while(q.size()) {
			q.pop();
		}
		for(int j = 1; j <= n; j++) {
			vis[j] = INF;
		}
		//skrg, jmlh, langkah
		cek = INF;
		q.push(mp(i, 0));
		while(q.size()) {
			int skrg, s;
			skrg = q.front().fs;
			s = q.front().sc;
			q.pop();
//			printf("-- %d %d --\n", skrg, s);
			if(s > cek) {
				break;
			}
			for(int j = 0; j < v[skrg].size(); j++) {
				if(v[skrg][j] == i) {
					cek = s + 1;
					vis[v[skrg][j]] = s + 1;
					break;
				}
				if(s + 1 < vis[v[skrg][j]]) {
					vis[v[skrg][j]] = s + 1;
					q.push(mp(v[skrg][j], s + 1));
				}
			}
			if(cek == s + 1) {
				break;
			}
		}
		if(vis[i] == INF) {
			printf("NO WAY\n");
		} else {
			printf("%d\n", vis[i]);
		}
	}
	return 0;
}
