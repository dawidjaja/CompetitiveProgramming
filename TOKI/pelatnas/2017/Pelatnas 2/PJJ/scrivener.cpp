
char last;
int n,skrg,p[1000005][25],lvl[1000005],m,pos,list[1000005],y;
char hrf[1000005],cmd,x;

void Init() {
	skrg=0;
	list[0]=-1;
	for(int i=0;i<=20;i++)
	{
		p[skrg][i]=-1;
	}
	pos=0;
	y=-1;
}

void TypeLetter(char L) {
	last = L;
	x = L;
	hrf[++pos]=x;
	lvl[pos]=++y;
	list[++skrg]=pos;
	p[pos][0]=list[skrg-1];
//			printf("%d --> %d\n",skrg,list[skrg]);
//			printf("  %d --> 0 %d\n",pos,p[pos][0]);
	for(int i=1;i<=20;i++)
	{
		int par;
		par=p[pos][i-1];
		if(par!=-1)
		{
//					printf("  %d --> %d %d\n",par,i,p[par][i-1]);
			p[pos][i]=p[par][i-1];
		}
		else
		{
			for(int j=i;j<=20;j++)
			{
				p[pos][j]=-1;
			}
			break;
		}
	}

}

void UndoCommands(int U) {
	int m = U;
	list[skrg+1]=list[skrg-m];
	skrg++;
	y=lvl[list[skrg]];
}

char GetLetter(int P) {
	int m = P;
	int temp;
	temp=list[skrg];
	for(int i=20;i>=0;i--)
	{
		if(p[temp][i]!=-1)
		{
			if(lvl[p[temp][i]]>=m)
			{
				temp=p[temp][i];
			}
		}
	}
	last = hrf[temp];
	return last;
}
