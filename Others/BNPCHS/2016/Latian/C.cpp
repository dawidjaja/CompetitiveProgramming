#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
int t,kcl,temp;
char angka[15];
int main ()
{
	scanf("%d",&t);
	gets(angka);
	for(int _=1;_<=t;_++)
	{
		gets(angka);
		for(int i=0;i<9;i++)
		{
			kcl+=(angka[i]-'0')*pow(10,8-i);
		}
		for(int i=0;i<9;i++)
		{
			temp=0;
			if(angka[i]=='0')
			{
				continue;
			}
			for(int j=0;j<9;j++)
			{
				temp+=(angka[(i+j)%9]-'0')*pow(10,8-j);
			}
			kcl=min(temp,kcl);
		}
		printf("Kasus #%d: %d\n",_,kcl);
	}
	return 0;
}
