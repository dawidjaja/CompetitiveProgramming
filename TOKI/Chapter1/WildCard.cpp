#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
char kunci[255],kata[255];
int n,temp,cek;
int main ()
{
	gets(kunci);
	scanf("%d",&n);
	gets(kata);
	if(strlen(kunci)==1)
	{
		for(int i=1;i<=n;i++)
		{
			gets(kata);
			puts(kata);
		}
	}
	else
	{
		for(int i=0;i<strlen(kunci);i++)
		{
			if (kunci[i]=='*')
			{
				temp=i;
				break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			gets(kata);
			cek=1;
			if(strlen(kata)>=strlen(kunci)-1)
			{
				for(int j=0;j<temp;j++)
				{
					if (kata[j]!=kunci[j])
					{
						cek=0;
						break;
					}
				}
				for (int j=strlen(kunci)-1;j>temp;j--)
				{
					if (kunci[j]!=kata[j-strlen(kunci)+strlen(kata)])
					{
						cek=0;
						break;
					}
				}
				if (cek==1)
				{
					puts(kata);
				}
			}
		}
	}
	return 0;
}
