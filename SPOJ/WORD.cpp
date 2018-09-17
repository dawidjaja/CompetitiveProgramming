#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <list>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int> 

using namespace std;

int n, k, itung, kluar[200005], msk[200005], mulai, wp[200005];
char kata[25], dftr[200005][25];
vector <int> v[200005];
map <long long, int> cek;
list<int> jln;

void euler(list<int>::iterator it, int skrg) {
	while(wp[skrg] < v[skrg].size()) {
		wp[skrg]++;
		jln.insert(it, v[skrg][wp[skrg]-1]);
		euler(it, v[skrg][wp[skrg]-1]);
	}
}
	
int main() {
	scanf("%d%d", &n, &k);
	itung = 1;
	for(int i = 1; i <= n-k+1; i++) {
		scanf("%s", kata);
		long long a = 0;
		long long b = 0;
		for(int j = 0; j < k-1; j++) {
			a += kata[j]-'A'+1;
			b += kata[j+1]-'A'+1;
			a *= 31;
			b *= 31;
		}
		if(!cek.count(a)) {
			for(int j = 0; j < k-1; j++) {
				dftr[itung][j] = kata[j];
			}
			cek[a] = itung++;
		}
		if(!cek.count(b)) {
			for(int j = 1; j < k; j++) {
				dftr[itung][j-1] = kata[j];
			}
			cek[b] = itung++;
		}
		v[cek[a]].push_back(cek[b]);
//		printf("-- %d %d --\n", cek[s1], cek[s2]);
		kluar[cek[a]]++;
		msk[cek[b]]++;
	}
//	for(int i = 1; i < itung; i++) {
//		printf("-- %d %d %d ", i, msk[i], kluar[i]);
//		tulis(dftr[i]);
//		for(int j = 0; j < v[i].size(); j++) {
//			printf("----- %d\n", v[i][j]);
//		} 
//	}
	mulai = 1;
	for(int i = 1; i < itung; i++) {
		if(kluar[i]-msk[i] == 1) {
			mulai = i;
			break;
		}
	}
//	printf("%d\n", mulai);
	jln.clear();
	euler(jln.begin(), mulai);
	for(int i = 0; i < k-1; i++) {
		printf("%c", dftr[mulai][i]);
	}
	for (list<int>::iterator it = jln.begin(); it != jln.end(); it++) {
		printf("%c", dftr[*it][k-2]);
	}
	printf("\n");
	return 0;
}
