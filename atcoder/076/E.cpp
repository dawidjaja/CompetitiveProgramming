#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int> 

using namespace std;

int c, r, n, a, b, x, y, ctr;
vector <pii> v;
stack <pii> st;

bool cek(int a, int b) {
	if(a == 0 || b == 0 || a == r || b == c) {
		return true;
	}
	return false;
}

int nilai(int a, int b) {
	if(b == 0) {
		return a;
	} else if(a == r) {
		return r + b;
	} else if(b == c) {
		return r + c + r - a;
	} else if(a == 0) {
		return r + c + r + c - b;
	}
}

int main() {
	scanf("%d%d%d", &r, &c, &n);
	ctr = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d%d", &a, &b, &x, &y);
		if(cek(a, b) && cek(x, y)) {
			ctr++;
			v.push_back(mp(nilai(a, b), ctr));
			v.push_back(mp(nilai(x, y), ctr));
			// printf("%d %d --> %d\n", a, b, nilai(a, b));
			// printf("%d %d --> %d\n", x, y, nilai(x, y));
		}
	}
	sort(v.begin(), v.end());
	int vs = v.size();
	for(int i = 0; i < vs; i++) {
		if(st.size() && st.top().sc == v[i].sc) {
			st.pop();
		} else {
			st.push(v[i]);
		}
	}
	if(st.size()) {
		printf("NO\n");
	}  else {
		printf("YES\n");
	}
	return 0;
}