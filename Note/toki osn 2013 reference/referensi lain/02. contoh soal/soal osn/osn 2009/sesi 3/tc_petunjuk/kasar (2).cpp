#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int x,y,lvl,arah;
} data;

int n,m,langkah,hasil=0;
char peta[201][201];
bool mark[201][201][22][4];
int movex[4]={-1,0,1,0};
int movey[4]={0,1,0,-1};
data push;
queue<data> q;
string str;

bool inside(int posx,int posy){
	if (posx<0 || posx>n || posy<0 || posy>m) 
		return 0;
		return 1;	
}

void bfs(string str,int lvl){
	data top=q.front();
	while (top.lvl==lvl && !q.empty()){
		q.pop();
		push=top;
		push.lvl=lvl+1;
		if (str=="KANAN"){
			push.arah=(push.arah+1)%4;
			if (inside (push.x,push.y) && !mark[push.x][push.y][lvl+1][push.arah]){
				mark[push.x][push.y][lvl+1][push.arah]=1;
				q.push(push);
			}
		} else if (str=="KIRI"){
			push.arah=(push.arah+3)%4;	
			if (inside (push.x,push.y) && !mark[push.x][push.y][lvl+1][push.arah]){
				mark[push.x][push.y][lvl+1][push.arah]=1;
				q.push(push);
			}
		} else{
			//puts("masuk sini");
			push.x+=movex[push.arah];
			push.y+=movey[push.arah];
			while (inside (push.x,push.y) && !mark[push.x][push.y][lvl+1][push.arah]){
				mark[push.x][push.y][lvl+1][push.arah]=1;
				q.push(push);
				push.x+=movex[push.arah];
				push.y+=movey[push.arah];
			}	
		}
		
		top=q.front();	
	}
}

int main(){
	int i,j,k;
	
	scanf("%d %d",&n,&m);
	for (i=0;i<n;i++)
		scanf("%s",peta[i]);
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			for (k=0;k<22;k++){
				if (peta[i][j]=='#'){
					mark[i][j][k][0]=1; 
					mark[i][j][k][1]=1;
					mark[i][j][k][2]=1;
					mark[i][j][k][3]=1;
				} else {
					mark[i][j][k][0]=0; 
					mark[i][j][k][1]=0;
					mark[i][j][k][2]=0;
					mark[i][j][k][3]=0;
					
				}
			}
			if (peta[i][j]=='H'){
				push.arah=0;
				push.x=i;
				push.y=j;
				push.lvl=0;
				q.push(push);
			}
		}	
	}
	char dumi;
	scanf("%d",&langkah);
	for (i=0;i<langkah;i++){
		cin >> str;
		bfs(str,i);
		/*for (int ii=0;ii<n;ii++){
			for (int jj=0;jj<m;jj++){
				cout << mark[ii][jj][i+1][0];
			}	
			cout << endl;
		}*/
	}
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			for (k=0;k<4;k++){
				if (mark[i][j][langkah][k] && peta[i][j]!='#'){
					hasil++;
					//printf("%d %d\n",i+1,j+1);
					break;	
				}	
			}	
		}	
	}
	cout << hasil << endl;
	for (i=0;i<n;i++){
		for (j=0;j<m;j++){
			for (k=0;k<4;k++){
				if (mark[i][j][langkah][k] && peta[i][j]!='#'){
					printf("%d %d\n",i+1,j+1);
					break;	
				}	
			}	
		}	
	}

	return 0;	
}
