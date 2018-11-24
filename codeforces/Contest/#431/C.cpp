#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

long long n;
vector <int> v;

int main() {
	scanf("%d", &n);
	if(n == 0) {
		printf("a\n");
		return 0;
	}
	while(n > 0) {
		long long a = n * 2;
		long long x = ceil(sqrt(a));
		if(x * (x - 1) / 2 > n) {
			x--;
		}
		v.push_back(x);
		n -= x * (x - 1) / 2;
	}
	for(long long i = 0; i < v.size(); i++) {
		for(long long j = 1; j <= v[i]; j++) {
			printf("%c", 'a' + i);
		}
	}
	printf("\n");
	return 0;
}