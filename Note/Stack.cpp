#include <algorithm>
#include <cstdio>
using namespace std;
int piv;
int list[1000];
void push(int a)
{
	list[piv]=a;
	piv++;
}
void pop()
{
	piv--;
}
int top()
{
	printf("%d",list[piv-1]);
}
int main()
{
	piv=1;
	return 0;
}
