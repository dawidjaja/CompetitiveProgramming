#include<stdio.h>
#include<ctime>
#include<cstdlib>

using namespace std;

int n,i;
long long t;
char filename[30];
bool uda[1000002];
int mod;
int j;

int main(){

	printf("N: ");
	scanf("%d",&n);
	
	printf("\nX max: ");
	scanf("%d",&mod);
	if(mod<2) mod=1000000;
	
	printf("\nfilename: ");
	scanf("%s",filename);
	
	for(i=0;i<1000002;i++) uda[i]=false;
	srand((unsigned)time(0));
	
	freopen(filename,"w",stdout);
	printf("%d\n",n);
	for(i=0;i<n;i++){
		do{
			t=((rand()*rand())%122 * rand())%(mod-1) +1;
		}while(uda[t]);
		printf("%lld\n",t);
		uda[t]=true;
	}
	fclose(stdout);
	return 0;
}

