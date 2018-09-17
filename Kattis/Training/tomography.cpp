#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n, m, x;
vector <int> row, col;

bool cmp(int a, int b) {
	return (a > b);
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		row.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		col.push_back(x);
	}
	sort(row.begin(), row.end(), cmp);
	for (int i = 0; i < m; i++) {
		sort(col.begin(), col.end(), cmp);
		for (int j = 0; j < n; j++) {
			if (row[i] > 0 && col[j] > 0) {
				row[i]--;
				col[j]--;
			}
		}
		if (row[i] != 0) {
			printf("No\n");
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (col[i] != 0) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}