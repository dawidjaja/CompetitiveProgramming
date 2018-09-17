#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector <long long> v;
long long n, ctr, tmp;

int main() {
	scanf("%lld", &n);
	v.push_back(1);
	v.push_back(2);
	while(v.back() + v[v.size() - 2] <= n) {
		v.push_back(v[v.size() - 1] + v[v.size() - 2]);
	}
	long long ans = v.size();
	printf("%lld\n", ans - 1);
	return 0;
}