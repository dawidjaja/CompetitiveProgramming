#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, list[100005], x, ctr;
vector <int> v[1005];

int main() {
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		scanf("%d", &x);
		v[x].push_back(i);
	}
	for(int i = 1; i < n; i++) {
		if(v[i].size() == 0) {
			continue;
		} else {
			ctr = 0;
			for(int j = 0; j < v[i].size(); j++) {
				if(v[v[i][j]].size() == 0) {
					ctr++;
				}
			}
			if(ctr < 3) {
				// printf("%d - %d\n", i, ctr);
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
	return 0;
}