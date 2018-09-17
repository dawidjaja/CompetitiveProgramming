#include <algorithm>
#include <cstdio>
#include <vector>

#define INF 1e16
#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long, long long> 
#define ppi pair<pii, long long>

using namespace std;

vector <ppi> v;
long long n, dp[100005], itung, a[100005], b;
pii list[100005], benda[100005];

bool cmp(pii a, pii b) {
	if(a.fs > b.fs) {
		return true;
	} else if(a.fs == b.fs) {
		return b.sc < a.sc;
	} else {
		return false;
	}
}

void insert(long long m, long long c, long long idx) {
//	printf("--- %lld %lld ---\n", m, c);
	while(v.size() >= 2) {
		pii a, b;
		a = v[v.size()-2].fs;
		b = v[v.size()-1].fs;
		double aa, bb;
		aa = b.sc - a.sc;
		bb = b.sc - c;
		aa /= a.fs - b.fs;
		bb /= m - b.fs;
		if(aa < bb) {
			break;
		}
		v.pop_back();
	}
	v.push_back(mp(mp(m, c), idx));
	return;
}

long long binser(long long x) {
	long long l, r, tgh;
	l = 0; r = v.size()-1;
	double zzz = x;
//	printf("cari -> %lld\n", x);
//	for(long long i = 0; i < v.size() ;i++) {
//			printf("v[%lld] = %lld %lld --> %lld\n", i, v[i].fs.fs, v[i].fs.sc, v[i].sc);
//		}
	while(l < r) {
//		printf("lrlrlrl %lld %lld\n", l, r);
		tgh = (l + r + 1) >> 1;
		pii a, b;
		a = v[tgh - 1].fs;
		b = v[tgh].fs;
		if(((double) b.sc - a.sc) / (a.fs - b.fs) < zzz) {
			l = tgh;
		} else {
			r = tgh - 1;
		}
	}
//	printf("llll %lld %lld \n", l, v[l].sc);
	return v[l].sc;
}

int main () {
	scanf("%lld", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &b);
		list[i] = mp(b, a[i]);
		dp[i] = INF;
	}
	dp[0] = 0;
//	for(long long i = 1; i <= n; i++) {
//		printf("%lld --> %lld %lld\n", i, list[i].fs, list[i].sc);
//	}
//	for(long long i = 1; i <= n; i++) {
//		for(long long j = 0; j < i; j++) {
//			dp[i] = min(dp[i], dp[j] + list[i].sc * list[j + 1].fs);
//		}
//	}
	dp[0] = 0;
	for(long long i = 1; i <= n; i++) {
		insert(list[i - 1].fs, dp[i-1], i);
		
		long long temp = binser(list[i].sc);
//		printf("temp -- %lld --\n", temp);
		
		dp[i] = dp[temp - 1] + list[i].sc * list[temp - 1].fs;
		
		
//		printf("%lld --->>>> %lld  dari %lld + %lld * %lld\n", i, dp[i], dp[temp - 1], list[i].sc, list[temp].fs);
//		
//		for(long long j = 1; j <= i; j++) {
//			printf("%lld\n", dp[j]);
//		}
//		
//		for(long long i = 0; i < v.size() ;i++) {
//			printf("v[%lld] = %lld %lld --> %lld\n", i, v[i].fs.fs, v[i].fs.sc, v[i].sc);
//		}
	}
	printf("%lld\n", dp[n]);
	return 0;
}
