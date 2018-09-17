#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <algorithm>
#include <list>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

char m[210][410];
int n;

void tri(int r, int c){
	REP(i,n/2){
		m[r+i][c-i] = '*';
		m[r+i][c+i] = '*';
	}
}

int main(){
	scanf("%d",&n);

	memset(m,' ',sizeof(m));
	tri(0,n-1);
	tri(n/2,n/2);
	tri(n/2,n-1+n/2);
	REP(i,n) m[n/2][n/2+i] = '*';
	REP(i,n*2) m[n-1][i] = '*';
	REP(i,n) printf("%.*s\n",n+i,m[i]);
}
