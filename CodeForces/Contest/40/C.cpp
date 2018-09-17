#include <algorithm>
#include <cstdio>
#include <cmath> 

using namespace std;

int n, a, b, ss, gde, gdex, gdey, x, y, ansx, ansy, kclx, kcly, list[200005];

int main() {
  scanf("%d", &n);
  ss = -1;
  gde = 0;
  for(int i = 1; i <= n; i++) {
    scanf("%d", &b);
    list[i] = b;
    gde = max(b, gde);
    if(i == 1) {
      kclx = 0;
      gdex = 0;
      kcly = 0;
      gdey = 0;
      x = 0;
      y = 0;
      a = b;
      if(n == 1) {
        printf("YES\n");
        printf("%d 1\n", a);
        return 0;
      }
      continue;
    }
    if(abs(a - b) == 1) {
      if(b - a == 1) {
        x++;
        gdex = max(gdex, x);
      } else {
        x--;
        kclx = min(kclx, x);
      }
    } else {
      int tmp = abs(a - b);
      if(ss == -1) {
        ss = tmp;
      } else {
        if(ss != tmp) {
          printf("NO\n");
          return 0;
        }
      }
      if(b > a) {
        y++;
        gdey = max(y, gdey);
      } else {
        y--;
        kcly = min(y, kcly);
      }
    }
    a = b;
  }

  if(ss == -1) {
    printf("YES\n");
    printf("%d 1\n", gde);
    return 0;
  }
  if(gdex - kclx > ss) {
    printf("NO\n");
    return 0;
  } else {
    for(int i = 2; i <= n; i++) {
      if(abs(list[i] - list[i - 1]) == 1) {
        if(list[i] > list[i - 1]) {
          if(list[i] % ss == 1) {
            printf("NO\n");
            return 0;
          }
        } else {
          if(list[i - 1] % ss == 1) {
            printf("NO\n");
            return 0;
          }
        }
      }
    }
    ansx = ss;
    ansy = ceil(1.0 * gde / ansx);
    printf("YES\n");
    printf("%d %d\n", ansy, ansx);
  }

  return 0;
}