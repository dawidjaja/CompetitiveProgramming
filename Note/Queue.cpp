#include <algorithm>
#include <cstdio>
using namespace std;
int head, tail;
int list[1000];
void push(int a)
{
	list[tail]=a;
	tail++;
}
void pop()
{
	head++;
}
int front()
{
	printf("%d",list[head]);
}
int main()
{
	head=0;
	tail=1;
	return 0;
}
