#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
vector <int> nyala[10];
vector <bool> v,cek[4][4][4][4][4][4][4][4][4];
int list[10],arr[10],n,aaaa;
char subtask[255],peta[255];
void pre()
{
	nyala[1].push_back(1);
	nyala[1].push_back(2);
	nyala[1].push_back(4);
	nyala[1].push_back(5);
	
	nyala[2].push_back(1);
	nyala[2].push_back(2);
	nyala[2].push_back(3);
	
	nyala[3].push_back(2);
	nyala[3].push_back(3);
	nyala[3].push_back(5);
	nyala[3].push_back(6);
	
	nyala[4].push_back(1);
	nyala[4].push_back(4);
	nyala[4].push_back(7);
	
	nyala[5].push_back(2);
	nyala[5].push_back(4);
	nyala[5].push_back(5);
	nyala[5].push_back(6);
	nyala[5].push_back(8);
	
	nyala[6].push_back(3);
	nyala[6].push_back(6);
	nyala[6].push_back(9);
	
	nyala[7].push_back(4);
	nyala[7].push_back(5);
	nyala[7].push_back(7);
	nyala[7].push_back(8);
	
	nyala[8].push_back(7);
	nyala[8].push_back(8);
	nyala[8].push_back(9);
	
	nyala[9].push_back(5);
	nyala[9].push_back(6);
	nyala[9].push_back(8);
	nyala[9].push_back(9);
}
int conv(char c)
{
	if (c=='s')
	{
		return 0;
	}
	else if (c=='p')
	{
		return 3;
	}
	else if (c=='g')
	{
		return 2;
	}
	else 
	{
		return 1;
	}
}
void itung(int x)
{
	if (x==10)
	{
//		printf("%d %d %d %d %d %d %d %d %d\n",list[1],list[2],list[3],list[4],list[5],list[6],list[7],list[8],list[9]);
		cek[list[1]][list[2]][list[3]][list[4]][list[5]][list[6]][list[7]][list[8]][list[9]]=v;
//		printf("%d\n",cek[list[1]][list[2]][list[3]][list[4]][list[5]][list[6]][list[7]][list[8]][list[9]].size());
		return;
	}
	for(int i=0;i<=3;i++)
	{
		bool b;
		b=i/2;
		v.push_back(b);
		b=i%2;
		v.push_back(b);
		for(int k=0;k<nyala[x].size();k++)
		{
			list[nyala[x][k]]+=i;
			list[nyala[x][k]]=list[nyala[x][k]]%4;
		}
		itung(x+1);
		v.pop_back();
		v.pop_back();
		for(int k=0;k<nyala[x].size();k++)
		{
			list[nyala[x][k]]+=3*i;
			list[nyala[x][k]]=list[nyala[x][k]]%4;
		}
	}
	return;
}
int main()
{
	pre();
	itung(1);
	gets(subtask);
	scanf("%d",&n);
	gets(subtask);
	for(int _=1;_<=n;_++)
	{
		gets(peta);
		arr[1]=conv(peta[0]);
		arr[2]=conv(peta[1]);
		arr[3]=conv(peta[2]);
		gets(peta);
		arr[4]=conv(peta[0]);
		arr[5]=conv(peta[1]);
		arr[6]=conv(peta[2]);
		gets(peta);
		arr[7]=conv(peta[0]);
		arr[8]=conv(peta[1]);
		arr[9]=conv(peta[2]);
//		printf("%d\n",cek[arr[1]][arr[2]][arr[3]][arr[4]][arr[5]][arr[6 	][arr[7]][arr[8]][arr[9]].size());
		for(int i=0;i<9;i++)
		{
			int temp;
			temp=cek[arr[1]][arr[2]][arr[3]][arr[4]][arr[5]][arr[6]][arr[7]][arr[8]][arr[9]][i*2]*2;
//			printf("qwer");
			temp+=cek[arr[1]][arr[2]][arr[3]][arr[4]][arr[5]][arr[6]][arr[7]][arr[8]][arr[9]][i*2+1];
//			printf("asdf");
//			printf("--%d--\n",temp);
			for(int j=0;j<temp;j++)
			{
				printf("%d",i+1);
			}
		}
		printf("\n");
	}
	return 0;
}
