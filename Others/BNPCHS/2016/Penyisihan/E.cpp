#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int t,cek,stok[10005],list[10005];
char a[105],b[105];
int main ()
{
	scanf("%d",&t);
	gets(a);
	for(int _=1;_<=t;_++)
	{
		cek=1;
		gets(a);
		gets(b);
		for(int i='A';i<='Z';i++)
		{
			stok[i]=0;
			list[i]=0;
		}
		for(int i=0;i<strlen(a);i++)
		{
			stok[a[i]]++;
		}
		for(int i=0;i<strlen(b);i++)
		{
			list[b[i]]++;
		}
		for(int i='A';i<='Z';i++)
		{
			if(list[i]>stok[i])
			{
				cek=0;
				break;
			}
		}
		if(cek==1)
		{
			printf("Kasus #%d: YA\n",_);
		}
		else
		{
			printf("Kasus #%d: TIDAK\n",_);
		}
	}
	return 0;
}
