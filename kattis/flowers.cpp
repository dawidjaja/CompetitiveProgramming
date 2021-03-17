#include <bits/stdc++.h>

using namespace std;

const double pi = M_PI;

double f2(double a, double b, double x) {
    double fx = a * exp(-x * x) + b * sqrt(x);
    return pi * fx * fx;
}

double quad(double a, double b, const int n = 1000) {
    double h = (b - a) / 2 / n;
    double v = f(a) + f(b); 
    for (int i = 1; i < n * 2; i++) {
        v += f(a + i * h) * (i & 1 ? 4 : 2);
    }
    return v * h / 3;
}

int main() {
    double v; int n; scanf("%lf%d", &v, &n);
    vector<pair<double, int> > delta;
    for (int i = 0; i < n; i++) {
        double a, b, h; scanf("%lf%lf%lf", &a, &b, &h);
        double cv = quad(0, h, [=](double x) { return f2(a, b, x);}, 1000000);
        // printf("%d %lf\n", i, cv);
        delta.emplace_back(fabs(v - cv), i);
    }
    sort(delta.begin(), delta.end());
    printf("%d\n", delta.begin()->second);
}
