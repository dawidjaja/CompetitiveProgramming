#include <algorithm>
#include <cstdio>
#include <queue>
#include <iostream>
#include <cmath>

using namespace std;

queue <long long> q;
long long p, k, cek;

int main() {
	scanf("%lld%lld", &p, &k);
	while(p != 0) {
		q.push(p % k);
		int tmp = ceil(abs(1.0 * p / k)) - abs(p);

		printf("%lld\n", p);
	}
	q.push(p);
	cout << q.size() << endl;
	cek = 0;
	while(q.size()) {
		if(cek) {
			printf(" ");
		}
		cek = 1;
		printf("%lld", q.front());
		q.pop();
	}
	printf("\n");
	return 0;
}