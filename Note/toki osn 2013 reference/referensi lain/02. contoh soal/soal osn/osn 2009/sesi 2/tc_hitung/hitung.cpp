#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

typedef vector<int> vi;

int n, m, K;
int main()
{
	scanf("%d %d %d",&n,&m,&K);
	K <?= n-1;
	
	vi v;
	int i;
	for (i=0; i<n; i++) v.push_back( i+1 );
	
	int cur = 0;
	for (i=0; i<K; i++)
	{
		cur = (cur+m-1) % v.size();
		v.erase(v.begin() + cur);
	}
	
	for (i=0; i<v.size(); i++) printf("%d\n", v[i]);
}