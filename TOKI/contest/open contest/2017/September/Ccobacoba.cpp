#include <algorithm>
#include <cstdio>
#include <cmath>
#define MOD 1000000000
using namespace std;
int a,b,c,d;
int G(int A,int B){
    double x;
    x=a;
    x=x/b;
    int ret;
    ret=ceil(x);
    return ret;
}
int F(int A, int B, int C, int D)
{
    int ans = 0;
    for(int i = 1 ;i<= A ;i++)
    {
        for (int j = 1 ;j <= B ;j++)
        {
            for (int k = 1 ;k<= C ;k++)
            {
                for(int l = 1 ;l<= D ;l++)
				{
                    if(i-j == k-l)
					{
//						printf("-- %d %d && %d %d --> %d\n",i,j,k,l,G(i,A) + G(j,B) + G(k,C) + G(l,D));
						ans = ans + G(i,A) + G(j,B) + G(k,C) + G(l,D);
                    }
					ans = ans %MOD;
                }
            }
        }
    }
//    if(ans%4!=0)
//    {
//    	printf("-- %d %d %d %d --\n",A,B,C,D);
//	}
    if(ans % 4  == 0)
	{
		ans = ans/4;
	}
    else
	{
		ans = ans - (ans % 4);
	}
    return ans;
}
int main ()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
//	for(int i=1;i<=a;i++)
//	{
//		for(int j=1;j<=b;j++)
//		{
//			for(int k=1;k<=c;k++)
//			{
//				for(int l=1;l<=d;l++)
//				{
//					printf("%d %d %d %d --> f(x) == %d\n",i,j,k,l,F(i,j,k,l));
//				}
//			}
//		}
//	}
	printf("%d\n",F(a,b,c,d));
}
