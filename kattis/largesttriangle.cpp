#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

vector <pii> v[2], ch;
pii list[5005];
int n;

bool concave(pii a, pii b, pii c) {
    long long dx = b.fs - a.fs;
    long long dy = b.sc - a.sc;
    long long ex = c.fs - b.fs;
    long long ey = c.sc - b.sc;
    if (dx * ey - dy * ex >= 0) {
        return true;
    }
    return false;
}

double getArea(int a, int b, int c) {
    double tmp = 0;
    tmp += 1.0 * ch[a].fs * ch[b].sc;
    tmp += 1.0 * ch[b].fs * ch[c].sc;
    tmp += 1.0 * ch[c].fs * ch[a].sc;
    tmp -= 1.0 * ch[a].sc * ch[b].fs;
    tmp -= 1.0 * ch[b].sc * ch[c].fs;
    tmp -= 1.0 * ch[c].sc * ch[a].fs;
    tmp = abs(tmp);
    //printf("area %d %d %d => %lf\n", a, b, c, tmp / 2);
    return tmp / 2;
}

double ternary(int a, int b, int c, int d) {
    //printf("-- %d %d %d %d \n", a, b, c, d);
    int len = b - a;
    if (len < 0) len += n;
    if (len <= 2) {
        double ret = 0;
        for (int i = a; i <= b; i++) {
            ret = max(ret, getArea(i, c, d));
        }
        return ret;
    }
    int mid1 = a + len / 3;
    if (mid1 >= n) mid1 -= n;
    int mid2 = a + 2 * len / 3;
    if (mid2 >= n) mid2 -= n;
    if (getArea(mid1, c, d) < getArea(mid2, c, d)) {
        return ternary(mid1, b, c, d);
    } else {
        return ternary(a, mid2, c, d);
    }
}

int dist(int a, int b) {
    int len = b - a;
    if (len < 0) len += n;
    return len;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &list[i].fs, &list[i].sc);
    }
    sort(list, list + n);
    /*
       for (int i = 0; i < n; i++) {
       printf("awal -- %d %d\n",  list[i].fs, list[i].sc);
       }
       */
    for (int i = 0; i < n; i++) {
        if (v[0].size() && v[0][v[0].size() - 1] == list[i]) {
            continue;
        }
        if (v[0].size() < 2) {
            v[0].push_back(list[i]);
        } else {
            while (v[0].size() >= 2 && concave(v[0][v[0].size() - 2], v[0][v[0].size() - 1], list[i])) {
                v[0].pop_back();
            }
            v[0].push_back(list[i]);
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (v[1].size() && v[1][v[1].size() - 1] == list[i]) {
            continue;
        }
        if (v[1].size() < 2) {
            v[1].push_back(list[i]);
        } else {
            while (v[1].size() >= 2 && concave(v[1][v[1].size() - 2], v[1][v[1].size() - 1], list[i])) {
                v[1].pop_back();
            }
            v[1].push_back(list[i]);
        }
    }
    for (int i = 0; i < v[0].size(); i++) {
        ch.push_back(v[0][i]);
        //printf("upper %d %d\n", v[0][i].fs, v[0][i].sc);
    }
    for (int i = 1; i < v[1].size() - 1; i++) {
        ch.push_back(v[1][i]);
        //printf("lower %d %d\n", v[1][i].fs, v[1][i].sc);
    }
    n = ch.size();
    /*
       for (int i = 0; i < n; i++) {
       printf("-- %d %d --\n", ch[i].fs, ch[i].sc);
       u

       }
       */
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = n - 1;
        l = (l + n) % n;
        r = (r + n) % n;
        int len = dist(l, r);
        //printf("ii %d %d %d\n", i, l, r);
        while (len > 2) {
            //for (int j = i + 1; j < n - 1; j++) {
            int mid1 = l + len / 3;
            if (mid1 >= n) mid1 -= n;
            int mid2 = l + 2 * len / 3;
            if (mid2 >= n) mid2 -= n;
            double sola = max(ternary(i, mid1, i, mid1), ternary(mid1, i, i, mid1));
            double solb = max(ternary(i, mid2, i, mid2), ternary(mid2, i, i, mid2));
            //printf("%d -- %d %d - %d - %d %d, %lf %lf\n", i, l, r, len, mid1, mid2, sola, solb);
            if (sola < solb) {
                l = mid1;
            } else {
                r = mid2;
            }
            len = dist(l, r);
        }
        for (int j = l; j <= r; j++) {
            ans = max(ans, ternary(i, j, i, j));
            ans = max(ans, ternary(j, i, i, j));
        }
    }
    printf("%lf\n", ans);
    return 0;
}


