#include <algorithm>
#include <cstdio>
using namespace std;
int r,c,list[100][100],cek,ilang,ctr,sdh;
char temp;
int main ()
{
    scanf("%d%d",&r,&c);
    scanf("%c",&temp);
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=c;j++)
        {
            scanf("%c",&temp);
            list[i][j]=temp-48;
        }
        scanf("%c",&temp);
    }
    sdh=0;
    while(sdh==0)
    {
        ilang=0;
        sdh=1;
        for (int i=1;i<=r;i++)
        {
            cek=1;
            for (int j=1;j<=c;j++)
            {
                if (list[i][j]==0)
                {
                    cek=0;
                }
            }
            if (cek==1)
            {
                for (int j=1;j<=c;j++)
                {
                    list[i][j]=0;
                    ilang=i;
                    sdh=0;
                }
            }
        }
        for (int j=1;j<=c;j++)
        {
            ctr=0;
            for (int i=r;i>=1;i--)
            {
                if (list[i][j]==1)
                {
                    if (i<ilang)
                    {
                        list[i+ctr][j]=list[i][j];
                        list[i][j]=0;
                    }
                    else
                    {
                        ctr=0;
                    }
                }
                else
                {
                    ctr++;
                }
            }
        }
    }
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=c;j++)
        {
            printf("%d",list[i][j]);
        }
        printf("\n");
    }
    return 0;
}
