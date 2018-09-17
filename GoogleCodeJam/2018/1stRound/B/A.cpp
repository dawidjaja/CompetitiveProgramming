#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

#define eps 1e-9
#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

double blkg;
vector<pii> v;
int tt, n, l, ans, list[100005];

int itung(double x) {
  double tx = x - trunc(x);
  int ret;
  if(tx >= 0.5) {
    ret = 0;
  } else {
    ret = (0.5 - tx - eps) / blkg + 1;
  }
  // printf("-- %lf %lf %d --\n", x, blkg, ret);
  return ret;
}

int main() {
  scanf("%d", &tt);
  for(int tc = 1; tc <= tt; tc++) {
    scanf("%d%d", &n, &l);
    blkg = 100.0 / n;
    blkg -= trunc(blkg);
    for(int i = 1; i <= l; i++) {
      scanf("%d", &list[i]);
    }
    if(blkg == 0){
      ans = 100;
      // printf("%lf", blkg);
    } else {
      ans = 0;
      // printf("blkg --> %lf\n", blkg);
      if(blkg < 0.5) {
        int sisa = n;
        v.clear();
        for(int i = 1; i <= l; i++) {
          v.push_back({itung(100.0 * list[i] / n), i});
          sisa -= list[i];
        } 
        sort(v.begin(), v.end());
        int vs = v.size();
        for(int i = 0; i < vs; i++) {
          if(sisa == 0) {
            break;
          } else {
            if(sisa <= v[i].fs) {
              list[v[i].sc] += sisa;
              sisa -= sisa;
            } else {
              list[v[i].sc] += v[i].fs;
              sisa -= v[i].fs;
            }
          }
        }
        ans = 0;
        // printf("-- %d--\n", sisa);
        if(sisa) {
          int tmp = itung(0);
          ans += (sisa / tmp - 1) * round(100.0 * tmp / n);
          sisa %= tmp;
          sisa += tmp;
          ans += round(100.0 * sisa / n);
        }
        for(int i = 1; i <= n; i++) {
          ans += round(100.0  * list[i] / n);
        }
        // printf("bbbbb");
      } else {
        int tmp = n;
        for(int i = 1; i <= l; i++) {
          ans += round(100.0 * list[i] / n);
          tmp -= list[i];
        }
        ans += tmp * round(100.0 / n);
        // printf("ccccc");
      }
    }
    printf("Case #%d: %d\n", tc, ans);
  }
  return 0;
}