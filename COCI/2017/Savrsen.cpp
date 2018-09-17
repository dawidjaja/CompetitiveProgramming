#include <algorithm>
#include <cstdio>
using namespace std;

int a, b, list[10000005];

//int itung(int x) {
//	int temp = 0;
//	for(int i = 1; i < x; i++) {
//		if(x%i == 0) {
//			temp+=i;
//		}
//	}
//	return temp;
//}

inline void sieve() {
	for(int i = 1; i <= b; i++) {
		for(int j = 2; j*i <= b; j++) {
			list[i*j] += i;
		}
	}
}

int main() {
	scanf("%d%d", &a, &b);
	sieve();
	int ans = 0;
	for(int i = a; i <= b; i++) {
		ans += abs(list[i] - i);
	}
	printf("%d\n", ans);
//	int jmlh = 0;
//	for(int i = 1; i <= 50; i++) {
//		jmlh += abs(itung(i)-i);
//		printf("%d --> %d , %d == %d\n", i, itung(i), abs(itung(i)-i), jmlh);
//	}
	return 0;
}
