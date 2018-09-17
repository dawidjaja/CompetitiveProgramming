#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,list[105],hsl,temp;
int main()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&list[i]);
			list[i]=list[i]%10;
		}
		hsl=0;
		temp=0;
		for(int i=1;i<=n;i++)
		{
			temp+=list[i];
			for(int j=i+1;j<=n;j++)
			{
				temp+=list[j];
				for(int k=j+1;k<=n;k++)
				{
					temp+=list[k];
					for(int l=k+1;l<=n;l++)
					{
						if((temp+list[l])%10==0)
						{
//							printf("%d %d %d %d\n",list[i],list[j],list[k],list[l]);
							hsl++;
						}
					}
					temp-=list[k];
				}
				temp-=list[j];
			}
			temp-=list[i];
		}
		printf("Kasus #%d: %d\n",_,hsl);
	}
	return 0;
}
