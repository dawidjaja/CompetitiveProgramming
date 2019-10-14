#include <bits/stdc++.h>

using namespace std;

const double INF = INFINITY;
double a, b, c, d, e, f, limit;

double getDist(double a, double b, double c) {
    return a * a + b * b + c * c;

}

double findMin2d(double x, double z) {
    double ta, tb, tc;
    ta = b;
    tb = d * z + f * x;
    tc = a * x * x + c * z * z + e * x * z - 1;

    double disc = tb * tc - 4 * ta * tc;

    if (disc < 0) return INF;
    if (ta == 0) {
        if (tb ==   
    }
    double res1, res2;
    res1 = (-tb + sqrt(disc)) / (2 * ta);

    return getDist(x, res1, z);
}



double findMin(double z) {

    double xl, xr;
    xl = -limit;
    xr = limit;

    int ctr = 20;
    while (xr - xl > 1e-12) {
        double midl = (xl * 2 + xr) / 3;
        double midr = (xl + xr * 2) / 3;

        //printf("--  xx %lf --- %lf %lf mid -> %lf %lf \n", z, xl, xr, midl, midr);
        double da = findMin2d(midl, z);
        double db = findMin2d(midr, z);
        printf("-- result %lf %lf\n", da, db);
	
        if (da == INF && b == INF) {
            xl = midl;
            xr = midr;
        } else if (da > db) {
            xl = midl;
        } else {
            xr = midr;
        }
    }

    return findMin2d(xl, z);
}

int main() {
    while ( scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f) != EOF) {
        double tmp = min(min(a, b), c);

        limit = 2.0 / tmp;
        double zl, zr;
        zl = 0;
        zr = limit;

        int ctr = 1;

        while (zr - zl > 1e-12) {
            //printf("- z - %lf %lf --\n", zl, zr);
            double midl = (zl * 2 + zr) / 3;
            double midr = (zl + zr * 2) / 3;

            double resl = findMin(midl);
            double resr = findMin(midr);

            if (resl > resr) {
                zl = midl;
            } else {
                zr = midr;
            }
        }
        printf("%.6lf\n", sqrt(findMin(zr)));
    }

    return 0;
}
