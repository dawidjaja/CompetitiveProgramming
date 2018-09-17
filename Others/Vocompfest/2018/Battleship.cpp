#include <algorithm>
#include <cstdio>

using namespaces std;

int main() {
  a[1] = b[2] = 1;
  a[3] = b[4] = -1;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for(int i = 1; i <= n; i++) {
    kapal[i] = m;
    for(int j = 1; j <= m; j++) {
      scanf("%d%d%d", &y, &x, &l);
      getchar();
      char c = getchar();
      arah = 0;
      if(c == 's') {
        arah = 1;
      } else if(c == 'e') {
        arah = 2;
      } else if(c == 'n') {
        arah = 3;
      } else if(c == 'w') {
        arah = 4;
      }
      for(int k = 0; k < l; k++) {
        if(list[y + a[arah]][x + b[arah]].fs != 0) {
          printf("ERROR_LOCATION_DETECTED\n");
          return 0;
        }
        list[y + a[arah]][x + b[arah]] = {i, j};
      }
    }
  }
  scanf("%d", &z);
  for(int i = 1; i <= z; i++) {
    if(kapal[i] == 0) {
      continue;
    }
    scanf("%d%d", &s, &t);
    if(list[s][t].fs != 0) {
      ancur[list[s][t].fs][list[s][t].sc]++;
      if(list[s][t].fs % n == i % n) {
        poin[i] -= ancur[list[s][t].fs][list[s][t].sc];
      } else {
        poin[i] += ancur[list[s][t].fs][list[s][t].sc];
      }
      list[s][t] = {0, 0};
    }
  }
  return 0;
}