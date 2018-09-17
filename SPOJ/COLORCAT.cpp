#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

#define getchar() getchar_unlocked()

using namespace std;

int n, k, ke, tiga[15], dp[100005][10], ptr, ctr, ttl, klmpk[20005], mulai, list[20005], dpn[20005], blkg[20005], arr[20005][10], temp;
char cc[20], ccc;


inline int ganti(int a, int b) {
	if(a == b){
		return a;
	} else if(a != 0 && b != 0){
		return 0;
	} else if(a != 1 && b != 1) {
		return 1;
	} else if(a != 2 && b != 2) {
		return 2;
	}
}

inline int getBit(int mask, int x) {
	int cpy = mask;
//	cpy = cpy % tiga[x+1];
	cpy = arr[cpy][x+1];
	cpy /= tiga[x];
	return cpy;
}

inline void tulis(int x) {
//	printf("-- ");
	for(int i = 0; i < 7; i++) {
		printf("%c", cc[getBit(x, i)]);
//		x /= 3;
	}
//	printf(" --\n");
}

inline void find(int mask, int dpn) {
	int cpy = mask;
	int temp, porer;
	//1234567
//		tulis(cpy);
	for(int i = 1; i <= 7; i++) {
//		printf("asdf");
		temp = getBit(cpy, i-1);
		if(i == 1) {
			porer = ganti(temp, dpn);
//			printf("-- %d %d --> %d--\n", temp, dpn, porer);
			cpy -= temp * tiga[i-1];
			cpy += porer * tiga[i-1];
		} else {
			int reri = getBit(cpy, i-2);
			porer = ganti(temp, reri);
			cpy -= temp * tiga[i-1];
			cpy += porer * tiga[i-1];
			cpy -= reri * tiga[i-2];
			cpy += porer * tiga[i-2];
		}
	}
//	tulis(mask);
//	printf("tambah %c jadi\n", cc[dpn]);
//	tulis(cpy);
//	printf("\n");
	dp[mask][dpn] = cpy;
}

inline void precompute() {
	tiga[0] = 1;
	for(int i = 1; i <= 8; i++) {
		tiga[i] = tiga[i-1] * 3;
	}
	for(int i = 0; i < tiga[8]; i++) {
		for(int j = 0; j <= 7; j++) {
			arr[i][j] = i % tiga[j];
		}
	}
	for(int i = 0; i < tiga[8]; i++){
		dpn[i] = getBit(i, 0);
		blkg[i] = i % tiga[6];
		for(int j = 0; j <= 2; j++) {
			find(i, j);
		}
	}
}


int main() {
	scanf("%d%d", &n, &k);
	cc[0] = 'W';
	cc[1] = 'R';
	cc[2] = 'G';
	while(true){
		ccc = getchar();
		if(ccc >= 'A' && ccc <= 'Z') {
			break;
		}
	}
	for(int i = 0; i < n; i++) {
		if(ccc == 'W') {
			list[i] = 0;
		} else if(ccc == 'R') {
			list[i] = 1;
		} else if(ccc == 'G') {
			list[i] = 2;
		}
		ccc = getchar();
	}
	
	if(n <= 7) {
		for(int j = 1; j <= k; j++) {
			for(int i = 0; i < n-1; i++) {
				list[i] = list[(i+1)] = ganti(list[i], list[(i+1)]);
			}
			list[n-1] = list[0] = ganti(list[0], list[n-1]);
		}
	} else {

		precompute();
		
		ptr = 2;
		ctr = 1;
		ttl = (n-1)/7;
		for(int i = 0; i < ttl; i++) {
			temp = 0;
			for(int j = 1; j <= 7; j++) {
				temp += list[i*7+j] * tiga[j-1];
			}
			klmpk[i] = temp;
		}
		mulai = ttl*7+1;
		for(int i = 1; i <= k; i++) {
			for(int j = 0; j < ttl; j++) {
				if(j == 0) {
					temp = ganti(list[0], dpn[klmpk[j]]);
					klmpk[j] = dp[klmpk[j]][list[0]];
					list[0] = temp;
				} else {
					int temp = getBit(klmpk[j-1], 6);
					int porer = ganti(temp, dpn[klmpk[j]]);
					klmpk[j] = dp[klmpk[j]][temp];
					klmpk[j-1] = blkg[klmpk[j-1]];
					klmpk[j-1] += porer * tiga[6];
				}
			}
			
			for(int j = mulai; j < n; j++) {
				if(j == mulai) {
					int temp = getBit(klmpk[ttl-1], 6);
					int porer = ganti(temp, list[j]);
					klmpk[ttl-1] = blkg[klmpk[ttl-1]];
					klmpk[ttl-1] += porer * tiga[6];
					list[j] = porer;
				} else {
					list[j] = list[j-1] = ganti(list[j], list[j-1]);
				}
			}
			if(mulai >= n) {
				int temp = getBit(klmpk[ttl-1], 6);
				int porer = ganti(temp, list[0]);
				klmpk[ttl-1] = blkg[klmpk[ttl-1]];
				klmpk[ttl-1] += porer * tiga[6];
				list[0] = porer;
			} else {
				list[0] = list[n-1] = ganti(list[0], list[n-1]);
			}
		}
	}
	printf("%c", cc[list[0]]);
	for(int j = 0; j < ttl; j++) {
		tulis(klmpk[j]);
	}
	for(int j = mulai; j < n; j++) {
		printf("%c", cc[list[j]]);
	}
	printf("\n");
	return 0;
}
