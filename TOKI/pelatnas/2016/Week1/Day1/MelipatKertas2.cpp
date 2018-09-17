#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
using namespace std;
int n;
deque <int> q;
char car[255],ccc;
int main ()
{
	scanf("%d",&n);
	gets(car);
	q.push_front(1);
	for (int i=2;i<=n;i++)
	{
		scanf("%c",&ccc);
		{
			if (ccc=='A')
			{
				if (i%2==0)
				{
					q.push_front(i);
				}
				else
				{
					q.push_back(i);
				}
			}
			else if (ccc=='B')
			{
				if (i%2==0)
				{
					q.push_back(i);
				}
				else
				{
					q.push_front(i);
				}
			}
		}
	}
	while (!q.empty())
	{
		printf("%d",q.front());
		q.pop_front();
		if (q.empty())
		{
			printf("\n");
		}
		else
		{
			printf(" ");
		}
	}
	return 0;
}
