#include <algorithm>
#include <cstdio>
#include <cmath>

#define fs first
#define sc second
#define pdd pair<double,double>

using namespace std;

int n, ans;
pdd list[1005];
double maks[1005];

double f(int a, int b) {
	double la = 2 * min(abs(list[a].fs - list[b].fs),
					90 - abs(list[a].fs - list[b].fs));
	double lo = min(abs(list[a].sc - list[b].sc),
					180 - abs(list[a].sc - list[b].sc));
	return (sqrt(la * la + lo * lo));
}

int main() {
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%lf%lf", &list[i].fs, &list[i].sc);
			maks[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double tmp = f(i, j);
				maks[i] = max(maks[i], tmp);
				maks[j] = max(maks[j], tmp);
			}
		}
		ans = 0;
		for (int i = 0; i < n; i++) {
			if(maks[i] >= maks[ans]) {
				ans = i;
			}
		}
		printf("%.2lf %.2lf\n", list[ans].fs, list[ans].sc);
	}
	return 0;
}