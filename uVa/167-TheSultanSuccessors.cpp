#include <algorithm>
#include <cstdio>
using namespace std;
int t,pos[10],list[10][10],maks,temp,tnd;
int main ()
{
	scanf("%d",&t);
	for (int _=1;_<=t;_++)
	{
		pos[1]=1;
		pos[2]=2;
		pos[3]=3;
		pos[4]=4;
		pos[5]=5;
		pos[6]=6;
		pos[7]=7;
		pos[8]=8;
		for (int i=1;i<=8;i++)
		{
			for (int j=1;j<=8;j++)
			{
				scanf("%d",&list[i][j]);
			}
		}
		maks=0;
		do
		{
			tnd=1;
			for (int i=1;i<=7;i++)
			{
				for (int j=i+1;j<=8;j++)
				{
					if (abs(i-j)==abs(pos[i]-pos[j]))
					{
						tnd=0;
					}
				}
			}
			if (tnd==1)
			{
				temp=0;
				for (int i=1;i<=8;i++)
				{
					temp+=list[i][pos[i]];
				}
				maks=max(maks,temp);
			}
		}
		while (next_permutation(pos+1,pos+9));
		if (maks>=100)
		{
			printf("  ");
		}
		else if (maks>=10)
		{
			printf("   ");
		}
		else
		{
			printf("    ");
		}
		printf("%d\n",maks);
	}
	return 0;
}
