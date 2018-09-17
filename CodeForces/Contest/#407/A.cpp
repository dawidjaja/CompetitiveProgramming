#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

long long n, list[100005], sel[100005];

int main() {
	scanf("%lld", &n);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld", &list[i]);
	}
	for(long long i = 1; i < n; i++) {
		sel[i] = abs(list[i + 1] - list[i]);
	}
	long long temp = 0;
	long long gde = 0;
	for(long long i = 1; i < n; i += 2) {
		gde = max(gde, temp + sel[i]);
		temp += sel[i] - sel[i + 1];
		if(temp < 0) {
			temp = 0;
		}
		gde = max(gde, temp);
		// gde = max(gde, temp + sel[i + 2]);
	}
	temp = 0;
	for(long long i = 2; i < n; i += 2) {
		gde = max(gde, temp + sel[i]);
		temp += sel[i] - sel[i + 1];
		if(temp < 0) {
			temp = 0;
		}
		gde = max(gde, temp);
		// gde = max(gde, temp + sel[i + 2]);
	}
	printf("%lld\n", gde);
	return 0;
}