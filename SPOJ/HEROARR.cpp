#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define mp make_pair
#define pdd pair<double, double>

using namespace std;



int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d%d%d%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2, &x3, &y3, &z3);
			list[i][1] = mp((((1.0) * x1) / z1), (((1.0) * y1) / z1));
			list[i][2] = mp((((1.0) * x2) / z2), (((1.0) * y2) / z2));
			list[i][3] = mp((((1.0) * x3) / z3), (((1.0) * y3) / z3));
		}
	}
}
