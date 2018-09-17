#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int list[10], cek, n;
char kata[5005], c;
vector <int> ans;

void dfs(int skrg) {
	if(skrg > n) {
		cek = 1;
		for(int i = 0; i < ans.size(); i++) {
			printf("%c", ans[i] + 'a' - 1);
		}
		return;
	}
	for(int i = 1; i <= 3; i++) {
		if(kata[skrg] != i && list[i] > 0) {
			ans.push_back(i);
			list[i]--;
			dfs(skrg+1);
			if(cek) {
				break;
			}
			list[i]++;
			ans.pop_back();
		}
	}
	if(cek) {
		return;
	}
}

int main() {
	scanf("%d", &n);
	getchar();
	for(int i = 1; i <= n; i++) {
		c = getchar();
		if(c == 'a') {
			list[1]++;
		} else if(c == 'b') {
			list[2]++;
		} else {
			list[3]++;
		}
	}
	getchar();
	for(int i = 1; i <= n; i++) {
		kata[i] = getchar();
		kata[i] -= 'a' - 1;
	}
	dfs(1);
	return 0;
}
