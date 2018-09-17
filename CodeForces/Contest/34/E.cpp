#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int n, k, dobel, beda[5005], cek, tmp;
char list[5005][5005];
map <char, int> udah;

int main() {
	scanf("%d%d", &n, &k);
	getchar();
	for(int i = 1; i <= n; i++) {
		scanf("%s", list[i]);
	}
	if(n == 1) {
		swap(list[1][0], list[1][1]);
		cout << list[1] << endl;
		return 0;
	}
	ii = 1;
	while(ii < n && list[ii] == list[ii + 1]) {
		ii++;
	}
	
	printf("-1\n");
	return 0;
}