#include <algorithm>
#include <cstdio>
#include <deque>

#define getchar_unlocked() getchar()
#define puf push_front
#define pub push_back
#define pof pop_front
#define pob pop_back

using namespace std;

deque <int> dpn, blkg;
int lptr, rptr;

int main() {
	scanf("%d", &tc);
	while(tc--) {
		n = 0;
		c = getchar();
		while(c != '-' && c != '^' && c != 'v') {
			c = getchar_unlocked();
		}
		while(c == '-' || c == '^' || c == 'v') {
			if(c == '^') {
				list[n++] = 2;
			} else if(c == '-') {
				list[n++] = 1;
			} else {
				list[n++] = 0;
			}
			c = getchar_unlocked();
		}
		dpn.clear();
		blkg.clear();
		cek = 0;
		lptr = 0;
		rptr = 0;
		for(int i = 0; i < n; i++) {
			if(list[i] == '^' || list[i] == 'v'){
				if(dpn == blkg) {
					
				}
			}
			dpn.puf(list[i-1]);
			blkg.pof();
		}
	}
	return 0;
}
