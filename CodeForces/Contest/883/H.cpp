#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>

#define fs first
#define sc second

using namespace std;

int n, gnp, gjl;
char c;
map <char, int> ctr;
vector <int> ev, od;

int main() {
	scanf("%d", &n);
	getchar();
	for(int i = 1; i <= n; i++) {
		c = getchar();
		// printf("-- %c --\n", c);
		ctr[c]++;
	}
	for(auto it = ctr.begin(); it != ctr.end(); it++) {
		// gnp += it->sc / 2;
		for(int i = 1; i <= it->sc / 2; i++) {
			ev.push_back(it->fs);
			gnp++;
		}
		if(it->sc % 2 == 1) {
			gjl++;
		// printf("-- %c -asdf-\n", it->fs);
			od.push_back(it->fs);
		}
	}
	// printf("--- %d %d ---\n", gnp, gjl);
	while(gjl != 0 && gnp > 0 && gnp % gjl != 0) {
		gnp--;
		gjl += 2;
		int temp = ev.back();
		ev.pop_back();
		od.push_back(temp);
		od.push_back(temp);
	}
	if(gjl == 0) {
		printf("1\n");
		string s;
		s = "";
		for(int i = 0; i < gnp; i++) {
			s += ev[i];
		}
		for(int i = gnp - 1; i >= 0; i--) {
			s += ev[i];
			// ev.pop_back();
		}
		cout << s;

	} else if(gnp != 0 && gnp % gjl == 0) {
		printf("%d\n", gjl);
		int cek = 0;

		for(int j = 0; j < gjl; j++) {
			if(cek) {
				printf(" ");
			}
			string s;
			s = "";
			for(int i = 1; i <= gnp / gjl; i++) {
				s += ev[ev.size() - gnp / gjl - 1 + i];
			}

			s += od[j];

			for(int i = 1; i <= gnp / gjl; i++) {
				s += ev[ev.size() - 1];
				ev.pop_back();
			}
			cek = 1;
			cout << s;
		}

	} else {
		printf("%d\n", n);
		int cek = 0;
		for(auto it = ctr.begin(); it != ctr.end(); it++) {
			for(int i = 1; i <= it->sc; i++) {
				if(cek) {
					printf(" ");
				}
				printf("%c", it->fs);
				cek = 1;
			}
		}
	}
	printf("\n");
	return 0;
}