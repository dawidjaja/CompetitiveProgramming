#include <algorithm>
#include <cstdio>
#define fs first
#define sc second
using namespace std;
double x;
int n,m,list[100005],p[100005],bnyk[100005],a,b,hsl;
pair <int, pair<int,int> > dum[100005],arr[100005];
int main ()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		bnyk[i] = 1;
		scanf("%d", &list[i]);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		dum[i].fs = min(a, b);
		dum[i].sc.fs = a;
		dum[i].sc.sc = b;
	}
	sort(dum + 1, dum + 1 + n);
	for (int i = 1; i <= m; i++) {
		arr[i].fs = dum[n-i+1].fs;
		arr[i].sc.fs = dum[n-i+1].sc.fs;
		arr[i].sc.sc = dum[n-i+1].sc.sc;
	}
	for (int i = 1; i <= m; i++) {
		if (arr[i].sc.fs > arr[i].sc.sc) {
			p[arr[i].sc.sc] = p[arr[i].sc.fs];
			int ta, tb;
			ta = bnyk[p[arr[i].sc.fs]];
			tb = bnyk[p[arr[i].sc.sc]];
			hsl += arr[i].fs * (ta + (tb * (ta + tb - 1)) - (ta * (ta - 1)) - (tb * (tb - 1)));
			bnyk[p[arr[i].sc.sc]] += bnyk[p[arr[i].sc.fs]];
		} else {
			p[arr[i].sc.fs] = p[arr[i].sc.sc];
			hsl += arr[i].fs * (bnyk[p[arr[i].sc.fs]] + bnyk[p[arr[i].sc.sc]] * (bnyk[p[arr[i].sc.fs]] + bnyk[p[arr[i].sc.sc]]-1)
					- (bnyk[p[arr[i].sc.fs]] * (bnyk[p[arr[i].sc.fs]] - 1)) - (bnyk[p[arr[i].sc.sc]] * (bnyk[p[arr[i].sc.sc]]-1)));
			bnyk[p[arr[i].sc.fs]] += bnyk[p[arr[i].sc.sc]];
		}
	}
	x = hsl/n;
	x = hsl/(n-1);
	printf("%.6lf\n",x);
	return 0;
}
