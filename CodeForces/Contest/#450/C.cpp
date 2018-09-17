#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

int bit[100005], hbit[100005], n, list[100005], vld[100005], hmpr[100005], ans, gde, tmp;
pii arr[100005];

bool bnyk(int x) {
	int ret = 0;
	for(int i = x; i >= 1; i -= (i & -i)) {
		ret += bit[i];
	}
	return ret;
}

int hit(int x) {
	int ret = 0;
	for(int i = x; i >= 1; i -= (i & -i)) {
		ret += hbit[i];
	}
	return ret;
}


int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		arr[i] = mp(list[i], i);
		vld[i] = vld[i - 1];
		if(list[i] == i && bnyk(i) == i - 1) {
			vld[i]++;
			for(int j = i; j <= n; j += (j & -j)) {
				bit[j] += 1;
			}
		}
		if(list[i] + 1 >= i) {

			hmpr[i]++;
		}
	}
	sort(arr + 1, arr + 1 + n);
	ans = 1;
	gde = 0;
	for(int i = 1; i <= n; i++){ 
		printf("%d ", vld[i]);
	}
	printf("\n");
	for(int i = 1; i <= n; i++) {
		//printf("watafak u segfault\n");
		//printf("zzzz");
		// printf("%d\n",i);
		int skrg = arr[i].sc;
		tmp = vld[skrg - 1];
		tmp += hit(n) - hit(skrg);
		if(hmpr[skrg]) {
			for(int j = skrg; j <= n; j += (j & -j)) {
				// printf("%d\n", j);
				hbit[j]++;
			}
		}
		printf("%d %d --> %d\n", i, skrg, tmp);
		if(tmp > gde) {
			gde = tmp;
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}