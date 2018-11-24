#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define pii pair<long long,long long>
#define mp make_pair
#define pps pair<pii,string>
#define fs first
#define sc second

using namespace std;

long long n, ans, ctr;
pps list[100005];

bool cmp(pps a, pps b) {
	// long long aa, bb;
	// aa = a.fs.sc - a.fs.fs;
	// bb = b.fs.sc - b.fs.fs;
	// if(aa < bb) {
	// 	return true;
	// } else if(aa == bb) {
		return a.fs.fs * b.fs.sc > b.fs.fs * a.fs.sc;
	// } else {
	// 	return false;
	// }
}

int main (){
	scanf("%lld", &n);
	for(long long i = 1; i <= n; i++) {
		cin >> list[i].sc;
		long long tmp = list[i].sc.length();
		long long ctr = 0;
		list[i].fs.fs = 0;
		list[i].fs.sc = 0;
		for(long long j = 0; j < tmp; j++) {
			if(list[i].sc[j] == 's') {
				list[i].fs.fs++;
			} else {
				list[i].fs.sc++;
			}
		}
	}
	ans = 0;
	sort(list + 1, list + 1 + n, cmp);
	for(long long i = 1; i <= n; i++) {
		long long tmp = list[i].sc.length();
		// cout << list[i].sc;
		for(long long j = 0; j < tmp; j++) {
			if(list[i].sc[j] == 's') {
				ctr++;
			} else {
				ans += ctr;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}