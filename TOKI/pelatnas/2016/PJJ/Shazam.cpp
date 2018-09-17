#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
int n,maks,cek;
char a[1005],b[1005],temp[1005];
int main ()
{
	scanf("%d",&n);
	gets(a);
	gets(a);
	for(int i=0;i<strlen(a);i++)
	{
		printf("%c",a[i]);
	}
	for(int _=2;_<=n;_++)
	{
		gets(b);
		maks=0;
		for(int i=1;i<=min(strlen(a),strlen(b));i++)
		{
			strncpy(temp,b,i);
			temp[i]='\0';
//			printf("--");
//			for(int k=0;k<strlen(temp);k++)
//			{
//				printf("%c",temp[k]);
//			}
//			printf("--\n");
			cek=1;
			for(int j=0;j<strlen(temp);j++)
			{
				if (temp[j]!=a[strlen(a)+j-strlen(temp)])
				{
					cek=0;
				}
			}
			if (cek==1)
			{
				maks=i;
			}
		}
//		printf("%d\n",maks);
		for(int i=maks;i<strlen(b);i++)
		{
			printf("%c",b[i]);
		}
		strncpy(a,b,strlen(b));
	}
	printf("\n");
}
