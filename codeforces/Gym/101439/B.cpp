#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

int c, n, list[20], temp, bit[30], q, m, soal[25];
char kota[105], cc;
string kos[25][25];
map <string, int> peta;

string toBinary(int n) {
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}

int main() {
	scanf("%d", &c);
	for(int i = 1; i <= c; i++) {
		scanf("%s%d", kota, &n);
		printf("--- asdf %d\n", i);
		peta[kota] = i;
		list[i] = 0;
		for(int k = 1; k <= n; k++) {
			temp = 0;
			// printf("qwerqwerqwer%d\n", k);
			getchar();
			for(int j = 0; j < 24; j++) {
				cc = getchar();
				cc == 'X' ? bit[23 - j] = 0 : bit[23 - j] = 1;
				temp *= 2;
				temp += bit[23 - j];
			}
			list[i] |= temp;
			scanf("%s", kota);
			for(int j = 0; j < 24; j++) {
				printf("%d", bit[23 - j]);
				if(bit[j] == 1) {
					kos[i][23 - j] = kota;
				}
			}
			printf("\n");
		}
		cout << "binbin " << toBinary(list[i]) << endl;
	}
	scanf("%d", &q);
	int lala = 1 << 24 - 1;
	while(q--) {
		printf("--- %d ---\n", q);
		scanf("%d", &m);
		temp = lala;
		for(int i = 1; i <= m; i++) {
			scanf("%s", kota);
			soal[i] = peta[kota];
		}
		for(int i = 1; i <= m; i++) {
			temp &= list[soal[i]];
		}
		if(temp == 0) {
			printf("No\n");
		} else {
			printf("Yes\n");
			int blkg = (temp & -temp);
			int porer = trunc(log2(blkg));
			for(int i = 1; i <= m; i++) {
				cout << " " << kos[soal[i]][blkg] << endl;
			}
		}
	}
	return 0;
}