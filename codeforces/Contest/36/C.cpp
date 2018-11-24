#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

vector <int> v;
int ctr[15], b[25], a_len, b_len, list[25];
char a[25], bb[25];

bool cmp(int a, int b) {
	return a > b;
}

bool f(int skrg, int bbs) {
	// printf("aaa %d %d -- ", skrg, bbs);
	// for(int i = 0; i < v.size(); i++) {
	// 	printf("%d ", v[i]);
	// }
	// printf("\n");
	if(skrg >= a_len) {
		for(int i = 0; i < skrg; i++) {
			printf("%d", v[i]);
		}
		return true;
	}
	if(bbs) {
		for(int i = 0; i < skrg; i++) {
			printf("%d", v[i]);
		}
		for(int i = 9; i >= 0; i--) {
			while(ctr[i]--) {
				printf("%d", i);
			}
		}
		return true;
	} else {
		bool valid, ada;
		ada = ctr[b[skrg]];
		valid = false;
		if(ada) {
			ctr[b[skrg]]--;
			v.push_back(b[skrg]);
			valid = f(skrg + 1, bbs);
			v.pop_back();
			ctr[b[skrg]]++;
		}
		if(!ada || !valid) {
			// printf("-- %d %d %d-- %d %d\n", skrg, bbs, b[skrg], ada, valid);
			bool bisa = false;
			if(b[skrg] != 0) {
				for(int i = b[skrg] - 1; i >= 0; i--) {
					// printf("--ini i %d\n", i);
					if(ctr[i]) {
						ctr[i]--;
						v.push_back(i);
						// printf("tambah %d\n", i);
						bisa = true;
						break;
					}
				}
				// printf("tes %d --> %d %d\n", skrg, bisa, v.back());
				if(bisa) {
					bool tmp =  f(skrg + 1, 1);
					ctr[v.back()]++;
					v.pop_back();
					return tmp;
				} else {
					return false;
				}
			} else {
				return false;
			}
		} else {
			return true;
		}
	}
}

int main() {
	cin >> a >> bb;
	a_len = strlen(a);
	b_len = strlen(bb);
	for(int i = 0; i < a_len; i++) {
		list[i] = a[i] - '0';
		ctr[list[i]]++;
	}
	for(int i = 0; i < b_len; i++) {
		b[i] = bb[i] - '0';
	}
	if(b_len > a_len) {
		sort(list, list + a_len, cmp);
		for(int i = 0; i < a_len; i++) {
			printf("%d", list[i]);
		}
		printf("\n");
		return 0;
	}
	f(0, 0);
	printf("\n");
	return 0;
}
