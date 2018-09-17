#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
char num[255];
string aaa;
int main ()
{
	scanf("%s",num);
	aaa=num;
	if (aaa[aaa.size()-1]=='0')
	{
		printf("2\n");
	}
	else
	{
		printf("1\n%c\n",aaa[aaa.size()-1]);
	}
	return 0;
}
