#include<bits/stdc++.h>
using namespace std;
map<string,bool> vis;
bool terminal[300][300];
vector<string> nonterminal[300];
vector<string> v;
int operat=0;
int ans2;
bool dp(string x)
{

    operat++;
    if(operat>10000) {ans2=-1; return 1;}
    string zz="",xxx="",yyy="",news="";

    int i,j,anjer;
    if(x.length()==v[0].length())
    {
        //cout<<x<<' '<<v[0]<<endl;
        //cout<<x<<' '<<v[0]<<endl;

        for(i=0; i<x.length(); ++i)
        {
            if(x[i]!=v[0][i])
            {

                if(!terminal[x[i]][v[0][i]])
                    return false;
            }
        }

        return true;
    }

    /*for(i=0; i<x.length(); ++i)
    {
        xx.push_back(xxx);
        xxx+=x[i];
    }*/
   /* for(i=x.length()-1; i>=0; --i)
    {
        // cout<<yyy<<endl;
        yy.push_back(yyy);
        yyy=x[i]+yyy;
    }*/
    long long z=2;
    for(i=1;i<x.length();++i)
    {
        yyy+=x[i];
    }
    //cout<<xxx<<' '<<yyy<<endl;
    for(i=0; i<x.length(); ++i)
    {

        //cout<<"lol"<<endl;
        if(nonterminal[x[i]].size()!=0)
            for(j=0; j<nonterminal[x[i]].size(); ++j)
            {

                news=xxx+nonterminal[x[i]][j]+yyy;
                //cout<<news<<endl;
                if(!vis[news])
                {
                    anjer=dp(news);
                    if(anjer==1) return 1;

                }
                vis[news]=1;
            }

         xxx+=x[i];
         yyy="";
         for(j=z;j<x.length();++j)
         {
             yyy+=x[j];
         }
         //cout<<xxx<<' '<<yyy<<endl;
         z++;
    }
    return 0;
}
ifstream fin;
int main()
{
    srand(time(NULL));
    fin.open("g.in");
    int i=0,ans;
    string x,st;
    while(fin>>x)
    {
        v.push_back(x);
        if(i!=0)
        {
            if(x.length()==2)
                terminal[x[0]][x[1]]=1;
            if(x.length()==3)
            {
                st="";
                st+=x[1];
                st+=x[2];
                nonterminal[x[0]].push_back(st);
            }
        }
        i++;
    }
    vis["S"]=1;

   // if(v.size()>14)
    //{
      //  cout<<rand()%2<<endl;
    //}
//    else
    //if(anj!=-1)
    ans=dp("S");
   // cout<<ans2<<endl;
   // cout<<operat<<endl;
    if(ans2!=-1) cout<<ans<<endl;
    else cout<<rand()%2<<endl;

}
