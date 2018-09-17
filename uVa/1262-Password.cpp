#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
int t,k,permut;
vector <char> v[10];
char a[105],b[105];
map <char,int> nyala[10];
int main ()
{
	scanf("%d",&t);
	for(int _=1;_<=t;_++)
	{
		scanf("%d",&k);
		k--;
		for(int i=0;i<5;i++)
		{
			nyala[i].clear();
			v[i].clear();
		}
		for(int i=1;i<=6;i++)
		{
			scanf("%s",a);
			for(int j=0;j<5;j++)
			{
				nyala[j][a[j]]=1;
//				printf(" %c -",a[j]);
			}
//			printf("\n");
		}
//		printf("%d???\n",nyala[0]['C']);
		for(int i=1;i<=6;i++)
		{
//			printf("--");
			scanf("%s",b);
			for(int j=0;j<5;j++)
			{
				if(nyala[j][b[j]]==1)
				{
					nyala[j][b[j]]=0;
//					printf("%d\n",j);
					v[j].push_back(b[j]);
				}
			}
		}
		permut=1;
		for(int i=0;i<5;i++)
		{
//			printf("%d -->",v[i].size());
			permut*=v[i].size();
			sort(v[i].begin(),v[i].end());
//			for(int j=0;j<v[i].size();j++)
//			{
//				printf(" %c -",v[i][j]);
//			}
//			printf("\n");
		}
//		printf(".-. %d\n",permut);
		if(permut==0 || k>=permut)
		{
			printf("NO\n");
			continue;
		}
		else
		{
//			printf("-");
			for(int i=0;i<5;i++)
			{
				permut/=v[i].size();
//				printf("%d %d -->",k,permut);
				printf("%c",v[i][k/permut]);
				k=k%permut;
			}
//			printf("-");
			printf("\n");
		}
	}
	return 0;
}
