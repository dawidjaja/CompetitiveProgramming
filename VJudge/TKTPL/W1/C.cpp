#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, k, tmp, num;
bool cek[1100000];
string ans;
pii pans;
vector <int> v;
queue <pii> q;

int main() {
	scanf("%d%d", &n, &k);
	ans = "";
	for(int i = 0; i < n; ++i) {
		num = 0;
		for(int j = 0; j < k; ++j) {
			scanf("%1d", &tmp);
			num *= 2;
			num += tmp;
		}
		if(!cek[num]) {
			q.push({num, k});
		}
		cek[num] = 1;
	}
	while(q.size()) {
		pii dpn = q.front();
		q.pop();
		pans = dpn;
		for(int i = 0; i < k; i++) {
			int x = dpn.fs ^ (1 << i);
			if(!cek[x]) {
				q.push({x, dpn.sc});
				cek[x] = 1;
			}
		}
	}
	int asdf = pans.fs;
	while(asdf) {
		v.push_back(asdf % 2);
		asdf /= 2;
	}
	while(v.size() < k) {
		v.push_back(0);
	}
	while(v.size()) {
		printf("%d", v.back());
		v.pop_back();
	}
	printf("\n");
	return 0;
}
