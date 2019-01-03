#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<long long,long long>
#define ppp pair<pii,pii>

using namespace std;

const long long INF = LLONG_MAX;

bool near(pii a, pii b, long long x) {
    return abs(a.fs - b.fs) < x;
}

long long getDist(pii a, pii b) {
    long long d = a.fs - b.fs;
    long long e = a.sc - b.sc;

    return d * d + e * e;
}

bool cmp(pii a, pii b) {
    if (a.sc == b.sc) return a.fs < b.fs;
    return a.sc < b.sc;
}

ppp closest(vector<pii> &v) {
    if (v.size() <= 3) {
        ppp ans;
        long long dist = INF;
        for (long long i = 0; i < v.size(); i++) {
            for (long long j = i + 1; j < v.size(); j++) {
                long long tmp = getDist(v[i], v[j]);
                if (tmp < dist) {
                    dist = tmp;
                    ans = {v[i], v[j]};
                }
            }
        }
        return ans;
    }
    vector <pii> l, r;
    for (long long i = 0; i < v.size() / 2; i++) {
        l.push_back(v[i]);
    }
    for (long long i = v.size() / 2; i < v.size(); i++) {
        r.push_back(v[i]);
    }

    ppp ans;
    long long dist;
    ppp pa = closest(l);
    ppp pb = closest(r);
    long long da = getDist(pa.fs, pa.sc);
    long long db = getDist(pb.fs, pb.sc);
    if (da < db) {
        ans = pa;
        dist = da;
    } else {
        ans = pb;
        dist = db;
    }
    //printf("%lld %lld\n", da, db);

    vector <pii> mid;
    for (long long i = 0; i < v.size(); i++) {
        if (near(v[i], v[v.size() / 2], dist)) {
            mid.push_back(v[i]);
        }
    }
    sort(mid.begin(), mid.end(), cmp);

    for (long long i = 0; i < mid.size(); i++) {
        for (long long j = i + 1; j < mid.size() && mid[j].sc - mid[i].sc < dist; j++) {
            long long tmp = getDist(mid[i], mid[j]);
            if (tmp < dist) {
                ans = {mid[i], mid[j]};
                dist = tmp;
            }
        }
    }
    /*
    printf("-- %lld %lld (%lld %lld) (%lld %lld)\n", 
            (long long) v.size(), dist, 
            ans.fs.fs, ans.fs.sc, ans.sc.fs, ans.sc.sc); 
    */
    return ans;
}

int main() {
    while (true) {
        long long n;
        scanf("%lld", &n);
        if (n == 0) {
            return 0;
        }
        vector <pii> pts;
        for (long long i = 0; i < n; i++) {
            double a, b;
            scanf("%lf%lf", &a, &b);
            a *= 100;
            b *= 100;
            long long ta = round(a);
            long long tb = round(b);
            pts.push_back({ta, tb});
        }
        sort(pts.begin(), pts.end());

        /*
        for (int i = 0; i < n; i++) {
            printf("-- %lld %lld\n", pts[i].fs, pts[i].sc);
        }
        */

        ppp ans = closest(pts);
        printf("%lld.%.2lld %lld.%.2lld %lld.%.2lld %lld.%.2lld\n", 
                ans.fs.fs / 100, abs(ans.fs.fs) % 100,
                ans.fs.sc / 100, abs(ans.fs.sc) % 100,
                ans.sc.fs / 100, abs(ans.sc.fs) % 100,
                ans.sc.sc / 100, abs(ans.sc.sc) % 100);
    }
    return 0;
}
