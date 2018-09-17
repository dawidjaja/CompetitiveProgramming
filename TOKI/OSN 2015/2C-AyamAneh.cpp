#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
char c,jwb[20],subtask[200];
int n,k,cek[150],pnjg[150],tes,x;
vector <int> v,a;
deque <int> dq;
int binser (int l,int r, char hrf)
{
	int piv;
	if (l==r)
	{
		return l;
	}
	piv=(l+r)/2+1;
	printf("TANYA ");
	for(int i=1;i<=piv;i++)
	{
		printf("%c",hrf);
		fflush(stdout);
	}
	printf("\n");
	fflush(stdout);
	scanf("%s",&jwb);
	if (jwb[0]=='Y')
	{
		return binser(piv,r,hrf);
	}
	else
	{
		return binser(l,piv-1,hrf);
	}
}
int main ()
{
	gets(subtask);
	scanf("%d%d",&n,&k);
//	if (subtask[3]==3)
//	{
//		
//		for(int i=1;i<=26;i++)
//		{
//			for(int i=1;i<=26;i++)
//			{
//				
//			}
//		}
//		return 0;
//	}
	
	
//	if (subtask[1]=='1')
//	{
//		for(int i=1;i<=3;i++)
//		{
//			c='A'+i-1;
//			pnjg[i]=binser(0,n,c);
//			printf("%d\n",pnjg[i]);
//			n-=pnjg[i];
//			if (pnjg[i]!=0)
//			{
//				v.push_back(c);
//				cek[c]=1;
//			}
//		}
//	}
//	else
	{
		for (int i=1;i<=26;i++)
		{
			c='A'+i-1;
			printf("TANYA %c\n",c);
			fflush(stdout);
			scanf("%s",&jwb);
			if (jwb[0]=='Y')
			{
				cek[c]=1;
				v.push_back(c);
			}
		}
	}
	dq.push_back(v[0]);
//	printf("%c\n",v[0]);
	cek[v[0]]=0;
	x=1;
	for(int i=1;i<v.size();i++)
	{
		tes=1;
		for(int j=0;j<v.size();j++)
		{
			if (cek[v[j]]==1)
			{
				printf("TANYA %c%c\n",dq.back(),v[j]);
				fflush(stdout);
				scanf("%s",&jwb);
				if (jwb[0]=='Y')
				{
					dq.push_back(v[j]);
					cek[v[j]]=0;
					tes=0;
					x++;
					break;
				}
			}
		}
		if (tes==1)
		{
			break;
		}
	}
	for(int i=1;i<v.size();i++)
	{
		if (x==v.size()-1)
		{
			for(int j=0;j<v.size();j++)
			{
				if (cek[v[i]]==1)
				{
					dq.push_front(v[i]);
				}
			}
			break;
		}
		if (x==v.size()-2)
		{
			for(int j=0;j<v.size();j++)
			{
				if (cek[v[i]]==1)
				{
					a.push_back(v[i]);
				}
			}
			printf("TANYA %c%c\n",a[0],dq.front());
			fflush(stdout);
			scanf("%s",&jwb);
			if (jwb[0]=='Y')
			{
				dq.push_front(a[0]);
				dq.push_front(a[1]);
			}
			else
			{
				dq.push_front(a[1]);
				dq.push_front(a[0]);
			}
		}
		for(int j=0;j<v.size();j++)
		{
			if (cek[v[j]]==1)
			{
				printf("TANYA %c%c\n",v[j],dq.front());
				fflush(stdout);
				scanf("%s",&jwb);
				if (jwb[0]=='Y')
				{
					dq.push_front(v[j]);
					cek[v[j]]=0;
					break;
				}
			}
		}
	}
	v.clear();
	while(!dq.empty())
	{
//		printf("%c",dq.front());
		v.push_back(dq.front());
		dq.pop_front();
	}
	for(int i=0;i<v.size()-1;i++)
	{
		pnjg[i]=binser(1,n,v[i]);
//		printf("%d\n",pnjg[i])...;
		n-=pnjg[i];
	}
	pnjg[v.size()-1]=n;
	printf("JAWAB ");
	fflush(stdout);
	for(int i=0;i<v.size();i++)
	{
//		printf("%d\n",pnjg[i]);
		for (int j=1;j<=pnjg[i];j++)
		{
			printf("%c",v[i]);
			fflush(stdout);
		}
	}
	printf("\n");
	fflush(stdout);
	return 0;
}
