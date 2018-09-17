#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

struct tgl {
  int d, m, y, h, min, s; 
  bool operator<(tgl x) {
    if(y == x.y) {
      if(m == x.m) {
        if(d == x.d) {
          if(h == x.h) {
            if(min == x.min) {
              return s < x.s;
            } else {
              return min < x.min;
            } 
          } else {
            return h < x.h;
          } 
        } else {
          return d < x.d;
        }
      } else {
        return m < x.m;
      }
    } else {
      return y < x.y;
    }
  }
  bool operator==(tgl x) {
    return (y == x.y && m == x.m && d == x.d &&
            h == x.h && min == x.min && s == x.s);
  }
};

pair<tgl,tgl> jdwl[5], baru;
int t, cek;

bool collide(pair<tgl,tgl> a, pair<tgl,tgl> b) {
  if(a.sc < b.fs || b.sc < a.fs) {
    return false;
  }
  return true;
}

int main() {
  scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    for(int i = 1; i <= 3; i++) {
      scanf("%d%d%d%d%d%d", &jdwl[i].fs.d, &jdwl[i].fs.m, &jdwl[i].fs.y, &jdwl[i].fs.h, &jdwl[i].fs.min, &jdwl[i].fs.s);
      scanf("%d%d%d%d%d%d", &jdwl[i].sc.d, &jdwl[i].sc.m, &jdwl[i].sc.y, &jdwl[i].sc.h, &jdwl[i].sc.min, &jdwl[i].sc.s);
    }
    scanf("%d%d%d%d%d%d", &baru.fs.d, &baru.fs.m, &baru.fs.y, &baru.fs.h, &baru.fs.min, &baru.fs.s);
    scanf("%d%d%d%d%d%d", &baru.sc.d, &baru.sc.m, &baru.sc.y, &baru.sc.h, &baru.sc.min, &baru.sc.s);
    cek = 0;
    for(int i = 1; i <= 3; i++) {
      if(collide(jdwl[i], baru)) {
        cek = 1;
      }
    }
    if(cek) {
      printf("Case #%d: COLLIDE\n", tc);
    } else {
      printf("Case #%d: OK\n", tc);
    }
  }
  return 0;
}