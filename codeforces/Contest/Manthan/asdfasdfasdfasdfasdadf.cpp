#include<bits/stdc++.h>
#define mod (long long)(1e9+7)
using namespace std;
long long n,m;
vector<long long> adj[100003];
long long lef[100003],rig[100003];
long long dp[100003][11][3],x,y;
void lcrs(long long now,long long par)
{
    long long i,tem;
     if(adj[now].size()==0)
     {
        return ;
     }
     if((adj[now].size()!=1)or(par==-1))
     {
        if(adj[now][0]!=par)
        {
             lef[now]=adj[now][0];
             tem=lef[now];
        }
        else
        {
            lef[now]=adj[now][1];
            tem=lef[now];
        }
        for(i=0;i<adj[now].size();++i)
        {
            if((adj[now][i]!=par)and(adj[now][i]!=lef[now]))
            {
                rig[tem]=adj[now][i];
                tem=adj[now][i];
            }
        }
        for(i=0;i<adj[now].size();++i)
        {
            if(adj[now][i]!=par)
            {
                lcrs(adj[now][i],now);
            }
        }
     }

}
//udah=kurang dari x ,lebih ,atau sama
long long rek(long long now,long long sisa,long long udh)
{
    long long ret=0,i;
    if(sisa<0) return 0;
    if(now==0)
    {
        if(sisa==0)
        {
            return 1;
        }
        else return 0;
    }

    if(dp[now][sisa][udh]!=-1)
    {
        return dp[now][sisa][udh];
    }
    ret=0;
    long long we;
    if(udh==1)
    {
        for(i=0;i<=sisa;++i)
        {
            we=rek(lef[now],i,0)*rek(rig[now],sisa-i,1);
            we%=mod;
            we*=(x-1);
            //we%=mod;
            ret+=we;
            ret%=mod;
        }
    }
    else if(udh==0)
    {
        //aku mau naruh
        for(i=0;i<=sisa-1;++i)
        {
            we=rek(lef[now],i,1)*rek(rig[now],sisa-1-i,0);
            we%=mod;
            ret+=we;
            ret%=mod;
        }
        //aku ga taruh
        for(i=0;i<=sisa;++i)
        {
            we=rek(lef[now],i,0)* rek(rig[now],sisa-i,0);
            we%=mod;
            we*=(x-1);
            we%=mod;
            ret+=we;
            ret%=mod;
            we=rek(lef[now],i,2)*rek(rig[now],sisa-i,0);
            we%=mod;
            we*=(m-x);
            //we%=mod;
            ret+=we;
            ret%=mod;
        }

    }
    else
    {

        //aku ga taruh
        for(i=0;i<=sisa;++i)
        {
            we=rek(lef[now],i,0)*rek(rig[now],sisa-i,2);
            we%=mod;
            we*=(x-1);
            //we%=mod;
            //cout<<rek(lef[now],i,0)<<' '<<rek(rig[now],sisa-i,2)<<endl;
            ret+=we;
            ret%=mod;
            we=rek(lef[now],i,2)*rek(rig[now],sisa-i,2);
            we%=mod;
            we*=(m-x);
            //we%=mod;
            ret+=we;
            ret%=mod;
        }

    }
    dp[now][sisa][udh]=ret;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp,-1,sizeof(dp));
    long long i,j,k;
    cin>>n>>m;
    for(i=0;i<n-1;++i)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    lcrs(1,-1);
    //cout<<lef[2]<<endl;
    cin>>x>>y;
    long long yo=0,xx;
    for(i=0;i<=y;++i)
    {
        xx=rek(lef[1],i,0)*(x-1);
        xx%=mod;
        yo+=xx;
        yo%=mod;
        yo+=rek(lef[1],i-1,1);
        yo%=mod;
        xx=rek(lef[1],i,2)*(m-x);
        xx%=mod;
        yo+=xx;
        yo%=mod;

    }

    //cout<<rek(2,0,2)<<endl;
    // if(n==2) cout<<1<<endl;
    // else
    cout<<yo<<endl;
}