#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

long long mlt, skrg, list[20], idx, brp, tc, n, temp;
char c, query;
map <long long, long long> satu, dua;

inline void tulis(long long skrg) {
	vector <long long> v;
	while(skrg) {
		v.push_back(skrg % 31);
		skrg /= 31;
	}
	printf("tulis ");
	for(long long i = v.size()-1; i >= 0; i--) {
		printf("%c", v[i] + 'a' - 1);
	}
	printf("\n");
}

void update(long long x) {
	mlt = 1;
	for(long long i = 5; i >= 0; i--) {
		skrg = x - mlt * list[i];
		if(!satu.count(skrg)) {
			//blom pernah ada
			satu[skrg] = list[i];
//			tulis(skrg);
		} else if(!dua.count(skrg)) {
			//satu dah ada, dua blom
			dua[skrg] = list[i];
			if(dua[skrg] < satu[skrg]) {
				swap(dua[skrg], satu[skrg]);
			}
		} else {
			//dua"nya ada
			if(list[i] < dua[skrg]) {
				//lbh bagus dari yg ke2
//				printf("qwer");
				dua[skrg] = list[i];
			}
			if(dua[skrg] < satu[skrg]) {
				//lbh bgus lagi dari yg 1
//				printf("asdf");
				swap(satu[skrg], dua[skrg]);
			}
		}
		mlt *= 31;
	}
	return;
}

void quer(long long x) {
	mlt = 1;
	for(long long i = 1; i <= 6; i++) {
		mlt *= 31;
	}
	idx = -1;
	brp = -1;
//	tulis(x);
	for(long long i = 0; i <= 5; i++) {
		mlt /= 31;
		skrg = x - mlt * list[i];
//		printf("--- %lld ---\n", mlt*list[i]);
//		tulis(skrg);
		if(satu.count(skrg)) {
			//ada kmungkinan
			if(satu[skrg] < list[i]) {
				//best choice
				idx = i;
				brp = satu[skrg];
				break;
			} else if(satu[skrg] == list[i]) {
				//sama dan g boleh dipilih
				if(!dua.count(skrg)) {
					//kalo ga ada kmungkinan2, brarti ga mungkin
					continue;
				} else {
					//pilih yg kedua
					idx = i;
					brp = dua[skrg];
					if(dua[skrg] < list[i]) {
						//kalo dah bagus
						break;
					}
				}
			} else {
				//kepaksa jelek
				idx = i;
				brp = satu[skrg];
			}
		} else {
			continue;
		}
	}
}

int main() {
	scanf("%lld", &tc);
	for(long long ii = 1; ii <= tc; ii++) {
		satu.clear();
		dua.clear();
		scanf("%lld", &n);
		printf("Test %lld\n", ii);
		for(long long k = 1; k <= n; k++) {
			getchar();
			query = getchar();
			if(query == 'W') {
				temp = 0;
				getchar();
				for(long long i = 0; i < 6; i++) {
					c = getchar();
					temp *= 31;
					temp += c - 'a' + 1;
					list[i] = c - 'a' + 1;
				}
//				for(long long i = 0; i < 6; i++) {
//					printf("%lld", list[i]);
//				}
//				printf("\n");
				update(temp);
			} else if(query == 'Q') {
				temp = 0;
				getchar();
				for(long long i = 0; i < 6; i++) {
					c = getchar();
					temp *= 31;
					temp += c-'a' + 1;
					list[i] = c-'a' + 1;
				}
				quer(temp);
				if(idx == -1) {
					printf("0\n");
				} else {
					for(long long i = 0; i < 6; i++) {
						if(i == idx) {
							printf("%c", 'a' + brp - 1);
						} else {
							printf("%c", 'a' + list[i] - 1);
						}
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}
