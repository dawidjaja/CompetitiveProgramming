#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

int n, ctr;
pii tmp;
vector <ppi> v[1005];

bool cmp(ppi a, ppi b) {
	return a > b;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &tmp.fs, &tmp.sc);
		v[min(tmp.sc / 1000, 999)].push_back({tmp, i});
	}
	ctr = 1;
	for(int i = 0; i < 1000; ++i) {
		if(i % 2) {
			sort(v[i].begin(), v[i].end());
		} else {
			sort(v[i].begin(), v[i].end(), cmp);
		}
		for(int j = 0; j < v[i].size(); j++) {
			printf("%d", v[i][j].sc);
			if(ctr++ == n) {
				printf("\n");
			} else {
				printf(" ");
			}
		}
	}
	return 0;
}