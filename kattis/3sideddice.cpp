#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

ppi pts[5];

int cross(pii a, pii b, pii c) {
    int df = b.fs - a.fs;
    int ds = b.sc - a.sc;
    int ef = c.fs - b.fs;
    int es = c.sc - b.sc;
    return df * es - ds * ef;
}

bool colin(pii a, pii b, pii c) {
    int dy = b.sc - a.sc;
    int dx = b.fs - a.fs;
    int ey = c.sc - b.sc;
    int ex = c.fs - b.fs;
    if (dy * ex == ey * dx) {
        return true;
    }
    return false;
}

bool in(pii a, pii b, pii c, pii d) {
    vector <pii> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    int dir;
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            dir = cross(v[i], v[(i + 1) % 3], d);
        } else {
            if (dir != cross(v[i], v[(i + 1) % 3], d)) {
                dir = 0;
            }
        }
    }
    if (dir == 0) {
        return false;
    } else {
        return true;
    }
}

bool inColin(pii a, pii b, pii c, pii d) {
    vector <pii> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(), v.end());
    
}

int main() {
	while (scanf("%d%d%d", &pts[0].fs.fs, &pts[0].fs.sc, &pts[0].sc)) {
		if (pts[0].fs.fs + pts[0].fs.sc + pts[0].sc == 0)
			return 0;
		for (int i = 1; i < 4; i++) {
			scanf("%d%d%d", &pts[i].fs.fs, &pts[i].fs.sc, &pts[i].sc);
		}
        if (colin(pts[0].fs, pts[1].fs, pts[2].fs)) {
            if (inColin(pts[0].fs, pts[1].fs, pts[2].fs, pts[3].fs)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            if (in(pts[0].fs, pts[1].fs, pts[2].fs, pts[3].fs)) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
        
	}
	return 0;
}
