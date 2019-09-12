#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

inline double cross(complex<double> a, complex<double> b) {
    return (conj(a) * b).imag();
}

pair<complex<double>, double> __centroid(vector<complex<double>> &points) {
    int n = points.size();
    auto centroid1 = (points[0] + points[n-2] + points[n-1]) / complex<double>(3, 0);
    auto area1 = abs(cross(points[0], points[n-2]) + cross(points[n-2], points[n-1]) + cross(points[n-1], points[0]));
    if (points.size() > 3) {
        points.pop_back();
        auto [centroid2, area2] = __centroid(points);
        return pair((centroid1 * area1 + centroid2 * area2)/(area1 + area2), area1 + area2);
    } else {
        return pair(centroid1, area1);
    }
}

complex<double> centroid(vector<complex<double>> points) {
    return __centroid(points).first;
}


int main() {
    scanf("%d", &n);
    vector<complex<double>> tps;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &pts[i].fs, &pts[i].sc);
        tps.emplace_back(pts[i].fs, pts[i].sc);
    }
    pii com;
    auto tcom = centroid(tps);
    com.fs = tcom.real();
    com.sc = tcom.imag();

    return 0;
}
