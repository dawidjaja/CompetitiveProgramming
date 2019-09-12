#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector <char> dpn, blkg;
char ans[20];
int n, midy, midx;

int dfs1(int y, int x) {
	if(y + 1 <= midy) {
		if (y + 1 == midy && x == midx) {
			dpn.push_back('D');
			return 1;
		}
		printf("? %d %d %d %d\n", y + 1, x, n, n);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == 'Y') {
			dpn.push_back('D');
			if(!dfs1(y + 1, x)) {
				dpn.pop_back();
			} else {
				return 1;
			}
		}
	}
	if(x + 1 <= midx) {
		if (y == midy && x + 1 == midx) {
			dpn.push_back('R');
			return 1;
		}
		printf("? %d %d %d %d\n", y, x + 1, n, n);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == 'Y') {
			dpn.push_back('R');
			if(!dfs1(y, x + 1)) {
				dpn.pop_back();
			} else {
				return 1;
			}
		}	
	}
	return 0;
}

int dfs2(int y, int x) {
	if(y + 1 <= n) {
		if (y + 1 == n && x == n) {
			dpn.push_back('D');
			return 1;
		}
		printf("? %d %d %d %d\n", 1, 1, y + 1, x);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == 'Y') {
			blkg.push_back('D');
			if(!dfs2(y + 1, x)) {
				blkg.pop_back();
			} else {
				return 1;
			}
		}		
	}
	if(x + 1 <= n) {
		if (y == n && x + 1 == n) {
			dpn.push_back('R');
			return 1;
		}
		printf("? %d %d %d %d\n", 1, 1, y, x + 1);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == 'Y') {
			blkg.push_back('R');
			if(!dfs2(y, x + 1)) {
				blkg.pop_back();
			} else {
				return 1;
			}
		}		
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		printf("? %d %d %d %d\n", 1, 1, n - i + 1, i);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == 'N') {
			continue;
		}
		printf("? %d %d %d %d\n", n - i + 1, i, n, n);
		fflush(stdout);
		scanf("%s", ans);
		if (ans[0] == 'Y') {
			midy = n - i + 1;
			midx = i;
			break;
		}
	}
	dfs1(1, 1);
	dfs2(midy, midx);
	for (int i = 0; i < (int) dpn.size(); i++) {
		printf("%c", dpn[i]);
	}
	printf("--");
	for (int i = 0; i < (int) blkg.size(); i++) {
		printf("%c", blkg[i]);
	}
	printf("\n");
	return 0;
}