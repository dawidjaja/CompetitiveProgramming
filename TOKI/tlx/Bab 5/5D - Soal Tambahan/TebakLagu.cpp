#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>
using namespace std;
char rit[1000],dummy;
int list[10000],jrk,n,pnjg,interval[1000],cek;
map <string,double> nada;
string awal,lagu;
int main ()
{
	gets(rit);
	awal=rit;
	nada["c."]=0;
	nada["c#"]=1;
	nada["d."]=2;
	nada["d#"]=3;
	nada["e."]=4;
	nada["f."]=5;
	nada["f#"]=6;
	nada["g."]=7;
	nada["g#"]=8;
	nada["a."]=9;
	nada["a#"]=10;
	nada["b."]=11;
	nada["C."]=12;
	nada["C#"]=13;
	nada["D."]=14;
	nada["D#"]=15;
	nada["E."]=16;
	nada["F."]=17;
	nada["F#"]=18;
	nada["G."]=19;
	nada["G#"]=20;
	nada["A."]=21;
	nada["A#"]=22;
	nada["B."]=23;
	jrk=((awal.size()/2)-1);
	for (int i=0;i<jrk;i++)
	{
		list[i]=nada[awal.substr((i+1)*2,2)]-nada[awal.substr(i*2,2)];
	}
	scanf("%d",&n);
	scanf("%c",&dummy);
	for (int num=1;num<=n;num++)
	{
		gets(rit);
		lagu=rit;
		pnjg=((lagu.size()/2)-1);
		for (int i=0;i<pnjg;i++)
		{
			interval[i]=nada[lagu.substr((i+1)*2,2)]-nada[lagu.substr(i*2,2)];
		}
		for (int i=0;i<pnjg-jrk+1;i++)
		{
			cek=1;
			for (int j=0;j<jrk;j++)
			{
				if (interval[j+i]!=list[j])
				{
					cek=0;
					break;
				}
			}
			if (cek==1)
			{
				printf("%d\n",num);
				return 0;
			}
		}
	}
	printf("#\n");
	return 0;
}
