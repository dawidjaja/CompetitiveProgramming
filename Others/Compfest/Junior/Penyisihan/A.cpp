#include <algorithm>
#include <cstdio>
using namespace std;
int n,i,blkg;
char c;
char kata[300005];
bool cek(char a)
{
	if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'
	|| a=='A' || a=='E' || a=='I' || a=='O' || a=='U')
	{
		return false;
	}
	return true;
}
int main ()
{
	scanf("%d",&n);
	scanf("%c",&c);
	gets(kata);
	i=0;
	while(cek(kata[i]))
	{
		i++;
	}
	blkg=n-1;
	while(cek(kata[blkg]))
	{
		blkg--;
	}
	for(int j=i;j<=blkg;j++)
	{
		printf("%c",kata[j]);
	}
	printf("\n");
	return 0;
}
