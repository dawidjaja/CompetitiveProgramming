#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
char kata[1005];
int n,tes;
bool cekpalindrome(int a,int b)
{
	for(int i=0;i<=(b/2)-1+(b%2);i++)
	{
		if(kata[a+i]!=kata[a+b-i])
		{
			return false;
		}
	}
	return true;
}
int main ()
{
	scanf("%d",&n);
	gets(kata);
	for (int _=1;_<=n;_++)
	{
		tes=0;
		gets(kata);
		for(int i=strlen(kata);i>=1;i--)
		{
			for(int j=0;j<=strlen(kata)-i;j++)
			{
				if(cekpalindrome(j,i))
				{
					tes=1;
					printf("Kasus #%d: %d\n",_,i+1);
					break;
				}
			}
			if(tes==1)
			{
				break;
			}
		}
		if(tes==1)
		{
			continue;
		}
		printf("Kasus #%d: 1\n",_);
	}
	return 0;
}
