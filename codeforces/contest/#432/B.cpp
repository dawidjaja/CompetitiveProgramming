#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long,long long>

using namespace std;

pii a, b, c;

long long pjg(pii a, pii b) {
	return (b.sc - a.sc) * (b.sc - a.sc) + (b.fs - a.fs) * (b.fs - a.fs);
}

int main() {
	scanf("%lld%lld%lld%lld%lld%lld", &a.fs, &a.sc, &b.fs, &b.sc, &c.fs, &c.sc);
	if(b.sc - a.sc == c.sc - b.sc && b.fs - a.fs == c.fs - b.fs) {
		printf("No\n");
		return 0;
	}
	if(pjg(a, b) == pjg(b, c)) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}