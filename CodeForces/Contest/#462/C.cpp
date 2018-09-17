#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, list[10005], cari, ans;
queue <int> q;
vector <pii> v;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
	}
	// cari = 1;
	for(int i = 1; i <= n; i++) {
		if(i == 1) {
			cari = list[i];
		}
		if(list[i] == cari) {
			v.push_back({i, list[i]});
			cari ^= 3;
		}
	}
	if(v.size() <= 3) {
		printf("%d\n", n);
		return 0;
	}
	for(int i = 0; i < v.size(); i++) {
		
	}
	v.push_back({n + 1, 0});
	
	printf("%d\n", ans);
	return 0;
}