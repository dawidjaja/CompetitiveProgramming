#include <algorithm>
#include <cstdio>
#include <cmath>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long,long long>

using namespace std;

long long n, list[1005], a, bctr, b, cek;
pii m, mb;

long long gcd(long long a, long long b) {
	a = abs(a);
	b = abs(b);
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
	scanf("%lld", &n);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &list[i]);
	}
	m = mp(list[2] - list[1], 1);
	cek = 1;
	for(long long i = 3; i <= n; i++) {
		if(m.fs * (i - 1) != m.sc * (list[i] - list[1])) {
			cek = 0;
			break;
		}
	}
	if(cek) {
		printf("No\n");
		return 0;
	}
	m = mp(list[3] - list[2], 1);
	cek = 1;
	for(long long i = 4; i <= n; i++) {
		if(m.fs * (i - 2) != m.sc * (list[i] - list[2])) {
			cek = 0;
			break;
		}
	}
	if(cek) {
		printf("Yes\n");
		return 0;
	}
	a = 1;
	bctr = 0;
	b = -1;
	m = mp(list[2] - list[1], 1);
	for(long long i = 2; i <= n; i++) {
		long long porer = gcd(list[i] - list[1], i - 1);
		m = mp((list[i] - list[1]) / porer, (i - 1) / porer);
		if(i == 2) {
			cek = 1;
			for(long long j = 3; j <= n; j++) {
				// printf("%lld\n", j);
				if(m.fs * (j - 1) != m.sc * (list[j] - list[1])) {
					if(bctr == 0) {
						bctr++;
						b = j;
					} else if(bctr == 1) {
						bctr++;
						long long temp = gcd(list[j] - list[b], j - b);
						mb = mp((list[j] - list[b]) / temp, (j - b) / temp);
						if(mb != m) {
							cek = 0;
							break;
						}
					} else {
						if(mb.fs * (j - b) != mb.sc * (list[j] - list[b])) {
							cek = 0;
							break;
						}
					}
				}
			}
			if(cek == 1) {
				printf("Yes\n");
				// printf("a");
				return 0;
			} else {
				bctr = 1;
				b = 2;
			}
		} else if(i == 3) {
			cek = 1;
			for(long long j = 4; j <= n; j++) {
				cek = 1;
				if(m.fs * (j - 1) != m.sc * (list[j] - list[1])) {
					if(bctr == 1) {
						bctr++;
						long long temp = gcd(list[j] - list[b], j - b);
						mb = mp((list[j] - list[b]) / temp, (j - b) / temp);
						if(mb != m) {
							cek = 0;
							break;
						}
					} else {
						if(mb.fs * (j - b) != mb.sc * (list[j] - list[b])) {
							cek = 0;
							break;
						}
					}
				}
			}
			if(cek == 1) {
				printf("Yes\n");
				// printf("b");
				return 0;
			} else {
				bctr = 2;
				b = 2;
				mb = mp(list[3] - list[2], 1);
			}
		} else {
			cek = 1;
			if(m != mb) {
				continue;
			}
			for(long long j = i + 1; j <= n; j++) {
				cek = 1;
				if(m.fs * (j - 1) != m.sc * (list[j] - list[1])) {
					if(mb.fs * (j - b) != mb.sc * (list[j] - list[b])) {
						cek = 0;
						// printf("-- %lld %lld %lld %lld --\n", mb.fs, mb.sc, list[j] - list[b], j - b);
						break;
					}
				}
			}
			if(cek == 1) {
				printf("Yes\n");
				// printf("c");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}