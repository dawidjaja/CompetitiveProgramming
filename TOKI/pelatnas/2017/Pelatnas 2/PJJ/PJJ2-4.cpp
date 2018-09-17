#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n,m,p,q,cek[1005];
vector <int> v[1005];

int dfs(int skrg,int dlm) {
	int ret = 0;
	if(dlm >= m) {
		ret++;
	}
	for(int i = 0; i < v[skrg].size(); i++) {
		ret+= dfs(v[skrg][i],dlm+1);
	}
	return ret;
}
int main () {
	scanf("%d",&n);
	for(int i = 1; i < n; i++) {
		scanf("%d%d", &p, &q);
		v[p].push_back(q);
		cek[q] = 1;
	}
	scanf("%d", &m);
	int mulai;
	for(int i = 1; i <= n; i++) {
		if(cek[i] == 0) {
			mulai = i;
			break;
		}
	}
	int ans = dfs(mulai,1);
	if(
	printf("%d\n",ans);
	return 0;
}
