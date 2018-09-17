#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
map <int,int> list;
int n,temp;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&temp);
		if (list[temp]==0)
		{
			list[temp]=1;
			printf("%d\n",temp);
		}
	}
	return 0;
}
