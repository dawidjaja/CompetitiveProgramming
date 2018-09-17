#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%1d", &list[i]);
	}
	x = 0;
	for(int i = 0; i < k; i++) {
		x *= 10;
		x += list[i];
	}
	return 0;
}