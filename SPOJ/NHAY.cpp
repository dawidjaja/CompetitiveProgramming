#include <algorithm>
#include <cstdio>
using namespace std;
int main ()
{
	while (scanf("%d",&n),n>=0)
	{
		getchar();
		gets(w);
		gets(s);
		if (s.size()>=n)
		{
			for (int i=0;i<=s.size()-n;i++)
			{
				cek=0;
				for (int j=0;j<n;j++)
				{
					if (w[j]!=s[i+j])
					{
						cek=1;
					}
				}
				if (cek==0)
				{
					printf("%d\n",i);
				}
			}
		}
	}
	return 0;
}
