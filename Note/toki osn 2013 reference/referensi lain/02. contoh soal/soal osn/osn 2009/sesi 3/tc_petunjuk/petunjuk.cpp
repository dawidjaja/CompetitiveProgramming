#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define REP(i,n) for (int i=0,_n=n; i<_n; i++)

set<pair<int,int> > pos;
char M[210][210];
int ok[2][210][210];
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
int R,C,N,D=0,cur=0;

int main(){
	scanf("%d %d",&R,&C);
	REP(i,R){
		scanf("%s",M[i]);
		REP(j,C) if (M[i][j]=='H')
			ok[cur][i][j] = 1;
	}
	
	scanf("%d",&N);
	REP(i,N){
		scanf("%s",M[R]);
		if (M[R][1]=='I') D = (D+3)%4;
		else if (M[R][1]=='A') D = (D+1)%4;
		else {
			int next = 1-cur;
			memset(ok[next],0,sizeof(ok[next]));
			REP(x,R) REP(y,C) if (ok[cur][x][y]) {
				for (int r=x,c=y; ; ){
					r += dr[D]; c += dc[D];
					if (r>=0 && r<R && c>=0 && c<C && M[r][c]!='#')
						ok[next][r][c] = 1;
					else break;
				}
			}
			cur = next;
		}
	}
	
	int cnt = 0;
	REP(i,R) REP(j,C) if (ok[cur][i][j]) cnt++;
	printf("%d\n",cnt);
	REP(i,R) REP(j,C) if (ok[cur][i][j]) printf("%d %d\n",i+1,j+1);
}
