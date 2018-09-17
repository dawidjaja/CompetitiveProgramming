#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int,int> 

using namespace std;

int t, n, u, m, outa[105], outb[105], a, b, list[105][105], out[105][105];
vector <int> satu[105], dua[105], aa;
queue <pii> q;

inline int baca()
{
	int temp = 0;
	char c;
	c = getchar_unlocked();
//	c = getchar();
	while(c < '0' || c > '9')
	{
//		c = getchar();
		c = getchar_unlocked();
	}
	while(c >= '0' && c <= '9')
	{
		temp *= 10;
		temp += c - '0';
//		c = getchar();
		c = getchar_unlocked();
	}
	return temp;
}
int main() {
	t = baca();
	while(t--) {
		n = baca();
		u = baca();
		for(int i = 1; i <= n; i++) {
			satu[i].clear();
			outa[i] = 0;
		}
		for(int i = 1; i <= u; i++) {
			a = baca();
			b = baca();
			outa[a]++;
			satu[b].push_back(a);
		}
		m = baca();
		u = baca();
		for(int i = 1; i <= m; i++) {
			dua[i].clear();
			outb[i] = 0;
		}
		for(int i = 1; i <= u; i++) {
			a = baca();
			b = baca();
			outb[a]++;
			dua[b].push_back(a);
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				list[i][j] = 2;
			}
		}
		while(q.size()) {
			q.pop();
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				out[i][j] = outa[i] + outb[j];
				if(out[i][j] == 0) {
					q.push(mp(i, j));
					list[i][j] = 1;
				}
			}
		}
//		for(int i = 1; i <= n; i++) {
//			printf("--- ");
//			for(int j = 1; j <= m; j++) {
//				printf("%d ", out[i][j]);
//			}
//			printf("---\n");
//		}
		while(q.size()) {
			pii skrg = q.front();
//			printf("----- %d %d -----\n", skrg.fs, skrg.sc);
			q.pop();
			
			for(int i = 0; i < satu[skrg.fs].size(); i++) {
				out[satu[skrg.fs][i]][skrg.sc]--;
//				printf("-- %d %d --\n", satu[skrg.fs][i], skrg.sc);
				if(list[satu[skrg.fs][i]][skrg.sc] == 3) {
					continue;
				}
				if(list[skrg.fs][skrg.sc] == 1) {
					list[satu[skrg.fs][i]][skrg.sc] = 3;
					q.push(mp(satu[skrg.fs][i], skrg.sc));
					continue;
				}
				if(out[satu[skrg.fs][i]][skrg.sc] == 0) {
					q.push(mp(satu[skrg.fs][i], skrg.sc));
				}
				if(list[skrg.fs][skrg.sc] == 3) {
					list[satu[skrg.fs][i]][skrg.sc] = 1;
				}
			}
			
			for(int i = 0; i < dua[skrg.sc].size(); i++) {
				out[skrg.fs][dua[skrg.sc][i]]--;
				if(list[skrg.fs][dua[skrg.sc][i]] == 3) {
					continue;
				}
				if(list[skrg.fs][skrg.sc] == 1) {
					list[skrg.fs][dua[skrg.sc][i]] = 3;
					q.push(mp(skrg.fs, dua[skrg.sc][i]));
					continue;
				}
				if(out[skrg.fs][dua[skrg.sc][i]] == 0) {
					q.push(mp(skrg.fs, dua[skrg.sc][i]));
				}
				if(list[skrg.fs][skrg.sc] == 3) {
					list[skrg.fs][dua[skrg.sc][i]] = 1;
				}
			}
		}
//		for(int i = 1; i <= n; i++) {
//			printf("---- ");
//			for(int j = 1; j <= m; j++) {
//				printf("%d ", out[i][j]);
//			}
//			printf("----\n");
//		}
//		for(int i = 1; i <= n; i++) {
//			printf("-- ");
//			for(int j = 1; j <= m; j++) {
//				printf("%d ", list[i][j]);
//			}
//			printf("--\n");
//		}
		if(list[1][1] == 1 && out[1][1] == 0) {
			printf("I lose\n");
		} else if(list[1][1] == 3) {
			printf("I win\n");
		} else {
			printf("Deadlock\n");
		}
	}
	return 0;
}
