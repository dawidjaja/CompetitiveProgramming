#include <algorithm>
#include <cstdio>

using namespace std;

int n, cek[105][105], ctr, xxx;

bool dua(int a, int b) {
	for(int i = b + 1; i <= n; i++) {
		if(cek[a][i] == 0 && cek[b][i] == 0) {
			cek[a][b] = cek[b][a] = cek[a][i] = cek[b][i] = cek[i][a] = cek[i][b] = 1;
			// printf("-- %d %d %d   %d--\n", a, b, i, cek[a][b]);
			xxx = i;
			printf("%c%c%c\n", 'A' + a - 1, 'A' + b - 1, 'A' + i - 1);
			return true;
		}
	}
	return false;
}

bool satu(int x) {
	for(int i = x + 1; i <= n; i++) {
		if(cek[x][i] == 0) {
			// printf("------- %d %d  %d--------\n", x, i, cek[x][i]);
			if(dua(x, i)) {
				return true;
			}
		}
	}
	return false;
}


int main() {
	n = 24;
	// freopen("out.txt", "w", stdout);
	// while(ctr < 100) {
	for(int i = 1; i <= n; i++) {
		cek[i][i] = 1;
	}
	int tes = 1;
	while(tes) {
		tes = 0;
		for(int i = 1; i <= n; i++) {
			if(satu(i)){
				tes = 1;
				ctr++;
				i = xxx;
				printf("-- %d\n", ctr);
			}
		}
	}
	for(int i = 1; i <= 24; i++) {
		for(int j = i + 1; j <= 24; j++) {
			if(cek[i][j] == 0) {
				ctr++;
				printf("%c%cY\n", 'A' + i - 1, 'A' + j - 1);
				printf("--->> %c %c\n", 'A' + i - 1, 'A' + j - 1);
			}
		}
	}
	printf("%d\n", ctr);
	return 0;
}