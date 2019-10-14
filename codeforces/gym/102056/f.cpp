#include <bits/stdc++.h>
 
#define fs first
#define sc second
 
using namespace std;
 
int tc;
 
template <class T> struct Point3D {
    typedef Point3D P;
    typedef const P& R;
    T x, y, z;
    explicit Point3D (T x = 0, T y=0, T z=0) : x(x), y(y), z(z) {}
    bool operator< (R p) const {
        return tie(x, y, z) < tie(p.x, p.y, p.z); }
    bool operator== (R p) const {
        return tie(x, y, z) == tie(p.x, p.y, p.z); }
    P operator+ (R p) const { return P(x+p.x, y+p.y, z+p.z); }
    P operator- (R p) const { return P(x-p.x, y-p.y, z-p.z); }
    P operator* (T d) const { return P(x*d, y*d, z*d); }
    P operator/ (T d) const { return P(x/d, y/d, z/d); }
    T dot(R p) const { return x*p.x + y*p.y + z*p.z; }
    P cross(R p) const {
        return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
    }
    T dist2() const { return x*x + y*y + z*z; }
    T dist() const { return sqrt((double)dist2()); }
};
 
template <class T> struct Point {
    typedef Point P;
    T x, y, z;
    explicit Point (T x=0, T y=0) : x(x), y(y) {}
    bool operator< (P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator== (P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+ (P p) const { return P(x+p.x, y+p.y); }
    P operator- (P p) const { return P(x-p.x, y-p.y); }
    P operator* (T d) const { return P(x*d, y*d); }
    P operator/ (T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this);}
    T dist2() const { return x*x + y*y; }
    T dist() const { return sqrt((double)dist2()); }
    P perp() const { return P(-y, x); }
};
 
typedef Point3D<double> P;
double segDist(P& s, P& e, P& p) {
    if (s == e) return (p-s).dist();
    auto d = (e-s).dist2(), t = min(d, max(.0, (p-s).dot(e-s)));
    return ((p-s)*d-(e-s)*t).dist()/d;
}
 
template<class P>
pair<P,P> circleTangents(const P &p, const P &c, double r) {
    P a = p-c;
    double x = r*r/a.dist2();
    double y = sqrt(abs(x-x*x));
    //printf("-- circle Tan %lf %lf\n", x, y);
    return make_pair(c+a*x+a.perp()*y, c+a*x-a.perp()*y);
}
 
template<class P>
double getAngle(const P& a, const P& b, const P& c) {
    return acos( ((a-b).dot(c-b)) / ((a-b).dist() * (c-b).dist()) );
}
 
int main() {
    scanf("%d", &tc);
    while (tc--) {
        Point3D<double> c;
        double r;
        scanf("%lf%lf%lf%lf", &c.x, &c.y, &c.z, &r);
        Point3D<double> a, b;
        scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z);
        if (a == b) {
            printf("0\n");
            continue;
        }
 
        double d = segDist(a, b, c);
        if (d >= r) {
            printf("%.8lf\n", (a-b).dist());
        } else {
            Point<double> p, q, s;
            p.x = 0; p.y = 0;
            q.x = (a-b).dist(); q.y = 0;
            s.x = sqrt((a-c).dist() * (a-c).dist() - d * d); s.y = d;
 
            /*
            printf("-- point awal %lf %lf\n", p.x, p.y);
            printf("-- point awal %lf %lf\n", q.x, q.y);
            printf("-- point awal %lf %lf\n", s.x, s.y);
            */
 
            double ans = 0;
            pair<Point<double> , Point<double> > tana = circleTangents(p, s, r);
            pair<Point<double> , Point<double> > tanb = circleTangents(q, s, r);
            ans += (tana.fs - p).dist();
            //printf("-- %lf\n", ans);
            ans += (tanb.fs - q).dist();
            //printf("tanb %lf %lf %lf %lf\n", tanb.fs.x, tanb.fs.y, tanb.sc.x, tanb.sc.y);
            //printf("-- %lf\n", ans);
            /*
               printf("\npoint -- %lf %lf\n", tana.fs.x, tana.fs.y);
               printf("point -- %lf %lf\n", tana.sc.x, tana.sc.y);
               printf("point -- %lf %lf\n", tanb.fs.x, tanb.fs.y);
               printf("point -- %lf %lf\n", tanb.sc.x, tanb.sc.y);
             */
            double tet1 = getAngle(tana.fs, s, tanb.fs);
            double tet2 = getAngle(tana.fs, s, tanb.sc);
            double tet3 = getAngle(tana.sc, s, tanb.fs);
            double tet4 = getAngle(tana.sc, s, tanb.sc);
            double teta = min(min(tet1, tet2), min(tet3, tet4));
            //printf("-- %lf\n", teta);
            ans += r * teta;
            printf("%.8lf\n", ans);
        }
    }
    return 0;
}

