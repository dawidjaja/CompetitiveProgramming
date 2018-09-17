#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

typedef vector<int> vi;
char buf[500];

#define SIZE(x) ((int)(x).size())

vi T;
vi one;

bool les(const vi& a, const vi& b)
{
	if (a.size() != b.size()) return a.size() < b.size();
	
	int i;
	for (i=SIZE(a)-1; i>=0; i--)
		if (a[i] != b[i]) return a[i] < b[i];
	return false;
}

vi add(const vi& a, const vi& b)
{
	if (SIZE(a) < SIZE(b)) return add(b,a);
	
	int i;
	int add = 0;
	int t;
	
	vi res;	
	for (i=0; i<b.size(); i++)
	{
		t = a[i] + b[i] + add;
		res.push_back(t%10);
		add = t/10;
	}
	for (; i<a.size(); i++)
	{
		t = a[i] + add;
		res.push_back(t%10);
		add = t/10;
	}
	if (add) res.push_back(1);
	return res;
}

void div2(vi& a)
{
	int i;
	int add = 0;
	for (i=SIZE(a)-1; i>=0; i--)
	{			
		a[i] += add*10;
		add = a[i]%2;
		a[i] /= 2;		
	}
	while (!a.empty() && a.back() == 0) a.pop_back();
}

vi mul(const vi& a, int z)
{
	if (z == 0 || a.empty()) return vi();
	vi res;
	int t, add = 0;
	
	int i;
	for (i=0; i<a.size(); i++)
	{
		t = a[i] * z + add;
		res.push_back(t%10);
		add = t/10;	
	}
	while (add)
	{
		res.push_back(add%10);
		add /= 10;
	}
	return res;
}

vi mul(const vi& a, const vi& b)
{
	if (a.empty() || b.empty()) return vi();
	
	vi res;
	int i;
	for (i=b.size()-1; i>=0; i--)
	{
		res = mul(res, 10);
		res = add(res, mul(a, b[i]));
	}
	return res;
}

vi proc(const vi& x)
{
	vi res = mul(x,x);
	res = add(res, x);
	return res;
}

void print (const vi& a)
{
	if (a.empty()) printf("0\n");
	else
	{
		int i;
		for (i=a.size()-1; i>=0; i--) printf("%d", a[i]);
		printf("\n");
	}
}

int main()
{
	one.clear();
	one.push_back(1);

	
	scanf("%s", buf);
	int len = strlen(buf);
	int i;

	T.clear();
	for (i=len-1; i>=0; i--)
		T.push_back( buf[i]-'0' );
	while (!T.empty() && T.back() == 0) T.pop_back();
	
	vi A;
	vi B;
	for (i=0; i<100; i++) B.push_back(0);
	B.push_back(1);

	vi mid, v;
	while (les(A, B))
	{
		mid = add(A, B);
		div2( mid );
		
		v = proc( mid );
		if (les(v, T)) 
		{
			A = mid;
			A = add(A, one);			
		}
		else
		{
			B = mid;
		}
	}
	
	print(A);
}