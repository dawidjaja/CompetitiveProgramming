#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, k, x, num;
vector <int> v[1000005];

int main() {
	while(scanf("%d%d", &n, &m) != EOF) {
		for(int i = 1; i <= 1000000; i++) {
			v[i].clear();
		}
		for(int i = 1; i <= n; i++) {
			scanf("%d", &num);
			v[num].push_back(i);
		}
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &k, &x);
			if(v[x].size() < k) {
				printf("0\n");
			} else {
				printf("%d\n", v[x][k - 1]);
			}
		}
	}
	return 0;
}