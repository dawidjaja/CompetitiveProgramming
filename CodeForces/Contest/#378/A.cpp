#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
char kata[205];
int temp,gede;
bool cek(char a)
{
	if(a=='A' || (a=='E' || (a=='I' || (a=='O' || (a=='U' || a=='Y')))))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main ()
{
	gets(kata);
	temp=0;
	gede=0;
	for(int i=0;i<strlen(kata);i++)
	{
		temp++;
		if(cek(kata[i]))
		{
			gede=max(gede,temp);
			temp=0;
		}
	}
	temp++;
	gede=max(gede,temp);
	printf("%d\n",gede);
	return 0;
}
