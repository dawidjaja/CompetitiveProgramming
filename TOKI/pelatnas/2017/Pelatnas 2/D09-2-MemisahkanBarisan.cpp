#include <algorithm>
#include <cstdio>
#include <vector>

#define INF 1e9
#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int> 
#define ppi pair<pii, int>

using namespace std;

int n, K, list[100005], dp[100005][205], ps[100005], simpen[100005][205];
vector <ppi> v;

double ptg(pii a, pii b) {
	double ret;
	ret = a.sc - b.sc;
	ret /= b.fs - a.fs;
	return ret;
}

void insert(int mm, int cc, int idx) {
	pii c;
	c = mp(mm, cc);
	while(v.size() >= 2) {
		pii a, b;
		a = v[v.size()-2].fs;
		b = v[v.size()-1].fs;
		if(ptg(a, b) < ptg(b, c)) {
			v.pop_back();
		} else {
			break;
		}
	}
	v.push_back(mp(c, idx));
	return;
}

int binser (int x) {
	int l = 0, r = v.size()-1, mid;
	double zzz = x;
	while(l < r) {
		mid = (l + r + 1) >> 1;
		pii a, b;
		a = v[mid - 1].fs;
		b = v[mid].fs;
		if(ptg(a, b) > zzz) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	return v[l].sc;
}

int main() {
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		ps[i] = list[i] + ps[i-1];
	}
	for(int k = 1; k <= K; k++) {
		v.clear();
		for(int i = 1; i <= n; i++) {
			insert(dp[i-1][k-1] - ps[i-1] * ps[i-1], ps[i-1], i);
			int temp = binser(ps[i]);
			dp[i][k] = ps[temp-1] * ps[i] + dp[temp-1][k-1] - ps[temp-1]*ps[temp-1];
			simpen[i][k] = temp;
		}
	}
	printf("%d\n", dp[n][K]);
	int temp = n;
	for(int i = K; i > 1; i--) {
		printf("%d ", simpen[temp][i]);
		temp = simpen[temp][i];
	}
	printf("%d\n", simpen[temp][1]);
	return 0;
}
