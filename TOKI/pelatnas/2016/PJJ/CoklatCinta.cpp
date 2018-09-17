#include <algorithm>
#include <cstdio>
using namespace std;
char subtask[255];
long long ctr,n,hsl;
int main()
{
	gets(subtask);
	scanf("%lld",&n);
//	for(n=1;n<=50;n++){
		hsl=1;
		hsl+=((n-1)/6)*(((n-1)/6)+1)*3;
		hsl+=((n-1)%6)*(((n-1)/6)+1);
		hsl+=n/6;
		printf("%lld\n",hsl);
//	}
	
	return 0;
}
