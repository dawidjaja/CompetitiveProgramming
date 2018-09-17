#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
int n, m, K;

char buf[50];

void transpose(vvi& v)
{
	int n = v.size();
	int m = v[0].size();
	
	vvi res(m, n);
	int i, j;
	for (i=0; i<n; i++) for (j=0; j<m; j++)
		res[j][i] = v[i][j];
	v = res;
}

void rot(vvi& v)
{
	int n = v.size();
	int m = v[0].size();
	
	vvi res(m, n);
	int i, j;
	for (i=0; i<n; i++) for (j=0; j<m; j++)
	{
		res[j][n-i-1] = v[i][j];
	}
	v = res;
}

void hor(vvi& v)
{
	int i, j;
	int n = v.size();
	int m = v[0].size();
	for (i=0; i+i<n; i++) for (j=0; j<m; j++)
		swap(v[i][j], v[n-i-1][j]);
}

void ver(vvi& v)
{
	int i, j;
	int n = v.size();
	int m = v[0].size();
	for (i=0; i<n; i++) for (j=0; j+j<m; j++)
		swap(v[i][j], v[i][m-j-1]);
}

int main()
{
	scanf("%d %d %d", &n, &m, &K);
	
	vvi v(n, m);	
	int i, j;
	for (i=0; i<n; i++) for (j=0; j<m; j++) scanf("%d", &v[i][j]);
	
	while (K--)
	{
		scanf("%s", buf);
		if (buf[0] == '/')
		{
			transpose( v );
			rot( v );
			rot( v );
		}
		else if (buf[0] == '\\')
		{
			transpose( v );
		}
		else if (buf[0] == '9')
		{
			rot( v );
		}
		else if (buf[0] == '1')
		{
			rot( v ); rot( v );
		}
		else if (buf[0] == '2')
		{
			rot( v );
			rot( v );
			rot( v );
		}
		else if (buf[0] == '_')
		{
			hor( v );
		}
		else if (buf[0] == '|')
		{
			ver( v );
		}
	}
	
	
	for (i=0; i<v.size(); i++)
	{
		for (j=0; j<v[i].size(); j++)
		{
			if (j) printf(" ");
			printf("%d", v[i][j]);
		}
		printf("\n");
	}
	
}