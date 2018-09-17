#include <iostream>
using namespace std;

int i,j,n;
int rr;
bool ever=false;

int main(){
	scanf("%d",&n);
	int sx=rand()%(10*n);
	int sy=rand()%(10*n);
	for (i=0;i<10*n;i++){
		for (j=0;j<10*n;j++){
			if (i==sx && j==sy){
				cout << 'H';
				continue;	
			}
			rr=rand()%101;
			if (rr<70)
				cout << '.';
			else
				cout << '#';
		}	
		cout << endl;
	}
	int jumlangkah=min(5+n,20);
	printf("%d\n",jumlangkah);
	for (i=0;i<jumlangkah;i++){
		rr=rand()%3;
		if (rr==0)
			puts("LURUS");
		if (rr==1)
			puts("KIRI");
		if (rr==2)
			puts("KANAN");	
	}
	return 0;	
}
