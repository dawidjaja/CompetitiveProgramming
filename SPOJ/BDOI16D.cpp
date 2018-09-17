#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

//#define getchar_unlocked() getchar()
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

struct node {
	set <int> s;
};

node* ke[100005];
int list[100005], ans[100005], hrg[100005], n, p, awal;
vector <int> v[100005];

void dfs(int skrg, int sblm, int x) {
	list[skrg] += x;
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm) {
			dfs(v[skrg][i], skrg, x + hrg[v[skrg][i]]);
		}
	}
}

inline int getS(node* skrg) {
	if(skrg == NULL) {
		return 0;
	}
	return skrg->s.size();
}

void dfslg(int skrg, int sblm) {
	for(int i = 0; i < v[skrg].size(); i++) {
		if(v[skrg][i] != sblm) {
			dfslg(v[skrg][i], skrg);
			int a = skrg;
			int b = v[skrg][i];
			if(getS(ke[a]) >= getS(ke[b])) {
				for(set<int> :: iterator it = ke[b]->s.begin(); it != ke[b]->s.end(); it++)  {
					ke[a]->s.insert(*it);
				}
				ke[skrg] = ke[a];
			} else {
				for(set<int> :: iterator it = ke[a]->s.begin(); it != ke[a]->s.end(); it++)  {
					ke[b]->s.insert(*it);
				}
				ke[skrg] = ke[b];
			}
		}
	}
	ans[skrg] = getS(ke[skrg]);
}

int main() {
//	scanf("%d", &n);
	n = baca();
	for(int i = 1; i <= n; i++) {
//		scanf("%d", &list[i]);
		list[i] = baca();
	}
	for(int i = 1; i <= n; i++) {
//		scanf("%d", &p);
		p = baca();
		v[p].push_back(i);
		if(p == 0) {
			awal = i;
		}
	}
	for(int i = 1; i <= n; i++) {
//		scanf("%d", &hrg[i]);
		hrg[i] = baca();
	}
	dfs(awal, -1, 0);

	for(int i = 1; i <= n; i++) {
		ke[i] = new node();
		ke[i]->s.insert(list[i]);
	}
	dfslg(awal, -1);
	for(int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
