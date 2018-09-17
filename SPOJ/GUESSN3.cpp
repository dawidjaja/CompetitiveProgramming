#include <algorithm>
#include <cstdio>
#include <assert.h>

using namespace std;

char jwb[10];
long long t, n, m;

long long tanya(long long a, long long b) {
	assert(m--);
	printf("QUERY %lld %lld\n", a, b);
	fflush(stdout);
	gets(jwb);
	if(jwb[0] == 'Y') {
		return 1;
	} else {
		return 0;
	}
}

void cari(long long l, long long r, long long lie) {
//	printf("%lld %lld %lld\n", l, r, lie);
	long long a, b, c;
	long long mid = (l + r) >> 1;
	if(l == r) {
		printf("ANSWER %lld\n", l);
		fflush(stdout);
		return;
	}
	if(lie == 1) {
		a = tanya(l, mid);
		b = tanya(l, mid);
		if(a == b) {
			if(a == 1) {
				cari(l, mid, lie);
			} else {
				cari(mid + 1, r, lie);
			}
		} else {
			c = tanya(l, mid);
			if(c == 1) {
				cari(l, mid, 0);
			} else {
				cari(mid + 1, r, 0);
			}
		}
	} else {
		a = tanya(l, mid);
		if(a == 1) {
			cari(l, mid, 0);
		} else {
			cari(mid + 1, r, 0);
		}
	}
	return;
}

int main() {
	scanf("%lld", &t);
	while(t--) {
		printf("START_GAME\n");
		fflush(stdout);
		scanf("%lld%lld", &n, &m);
		getchar();
		cari(1, n, 1);
	}
}
