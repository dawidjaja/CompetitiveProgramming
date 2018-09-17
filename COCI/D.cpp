#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<long long,long long>

using namespace std;

vector <short> hsl;
long long n, cek[1000005], root, ans;
pii list[1000005];

long long dfs(long long skrg) {
	long long a, b, ret;
	if(list[skrg].fs <= 0) {
		a = -list[skrg].fs;
	} else {
		a = dfs(list[skrg].fs);
	}
	if(list[skrg].sc <= 0) {
		b = -list[skrg].sc;
	} else {
		b = dfs(list[skrg].sc);
	}
	return max(a, b) * 2;
}

int main () {
	scanf("%lld", &n);
	for(long long i = 1; i <= n; i++) {
		scanf("%lld%lld", &list[i].fs, &list[i].sc);
		if(list[i].fs > 0) {
			cek[list[i].fs] = 1;
		}
		if(list[i].sc > 0) {
			cek[list[i].sc] = 1;
		}
	}
	for(long long i = 1; i <= n; i++) {
		if(cek[i] == 0) {
			root = i;
			break;
		}
	}
	ans = dfs(root);
	while(ans > 0) {
		hsl.push_back(ans & 1);
		ans = ans >> 1;
	}
	while(hsl.size()) {
		printf("%d", hsl[hsl.size()-1]);
		hsl.pop_back();
	}
	printf("\n");
	return 0;
}
