#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <algorithm>
#include <list>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

int n,m,x,y,q,a[100000];

int main(){
	scanf("%d %d",&n,&m);
	REP(i,n) a[i] = i;
	REP(i,m){
		scanf("%d %d",&x,&y);
		swap(a[x-1],a[y-1]);
	}
	scanf("%d",&q);
	while (q--){
		scanf("%d",&x);
		printf("%d\n",a[x-1]+1);
	}
}
