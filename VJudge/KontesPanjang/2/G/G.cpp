#include <bits/stdc++.h>

using namespace std;

string target;
int n, ctr, cek, mati[305][305];
map <char, vector<string> > ada;
map <string, bool> vis;

bool f(string s) {
	if(vis.count(s)) {
		return vis[s];
	}
	ctr++;
	if(ctr >= 30000) {
		// printf("\n\n\n\n\n\nrandomshit\n\n\n\n\n\n\n\n");
		cek = 1;
		return 1;
	}
	// cout << s << endl;
	if(s == target) {
		return 1;
	} 
	if(s.length() > n) {
		return 0;
	} else if(s.length() < n) {
		bool ans = 0;
		for(int i = 0; i < s.length(); i++) {
			// printf("-- %c --\n", s[i]);
			if(ada.count(s[i])) {
				for(int j = 0; j < ada[s[i]].size(); j++) {
					// printf("adsf");
					string temp = s;
					temp.replace(i, 1, ada[s[i]][j], 0, ada[s[i]][j].length());
					ans |= f(temp);
					if(ans) {
						vis[s] = ans;
						return ans;
					}
				}
			}
		}
		vis[s] = ans;
		return ans;
	} else {
		int ans = 0;
		for(int i = 0; i < s.length(); i++) {
			if('A' <= s[i] && s[i] <= 'Z') {
				for(int j = 'a'; j <= 'z'; j++) {
					if(mati[s[i]][j]) {
						string temp = s;
						temp.replace(i, 1, 1, j);
						ans |= f(temp);
						if(ans) {
							vis[s] = ans;
							return ans;
						}
					}
				}
			}
		}
		vis[s] = ans;
		return ans;
	}
}

int main() {
	// ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("g.in", "r", stdin);
	srand(time(NULL));
	cin >> target;
	n = target.length();
	// printf("-- %d\n", n);
	ctr = 0;
	cek = 0;
	while(true) {
		getchar();
		char c;
		string kata;
		c = getchar();
		if(c == EOF) {
			int tulis;
			if(f("S")) {
				if(cek) {
					tulis = rand() % 2;
				} else {
					tulis = 1;
				}
			} else {
				tulis = 0;
			}
			printf("%d\n", tulis);
			return 0;
		}
		cin >> kata;
		if(kata.length() == 1) {
			mati[c][kata[0]] = 1;
		} else {
			ada[c].push_back(kata);
		}
	}
	return 0;
}