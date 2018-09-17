#include <algorithm>
#include <cstdio>
#include <queue>

#define fs first
#define sc second
#define pii pair<int,int>
#define pip pair<int,pii>

using namespace std;

int a[5], b[5], n, m, s, t, x, y, cek, tt, vis[205][205];
char list[205][205];
priority_queue <pip> pq;

bool dlm(int y, int x) {
  return ((0 <= y) && (y < n) && (0 <= x) && (x < m));
}

int main() {
  a[1] = b[2] = 1;
  a[3] = b[4] = -1;
  scanf("%d", &tt);
  for(int tc = 1; tc <= tt; tc++) {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) {
      getchar();
      for(int j = 0; j < m; j++) {
        list[i][j] = getchar();
        vis[i][j] = 0;
      }
    }
    while(pq.size()) {
      pq.pop();
    }
    scanf("%d%d", &t, &s);
    scanf("%d%d", &y, &x);
    if(t == y && s == x) {
      int ans = (list[s][t] == '#') ? 1 : 0;
      printf("Case #%d: %d\n", tc, ans);
      continue;
    }
    pq.push({((list[s][t] == '#') ? -1 : 0), {t, s}});
    cek = 0;
    while(pq.size()) {
      int jrk = -pq.top().fs;
      int sy = pq.top().sc.fs;
      int sx = pq.top().sc.sc;
      // printf("-- %d %d %d --\n", jrk, sy, sx);
      pq.pop();
      for(int i = 1; i <= 4; i++) {
        int ty = sy + a[i];
        int tx = sx + b[i];
        if(vis[ty][tx] == 0 && dlm(ty, tx)) {
          vis[ty][tx] = 1;
          int hrg = jrk + (list[ty][tx] == '#' ? 1 : 0);
          if(ty == y && tx == x) {
            printf("Case #%d: %d\n", tc, hrg);
            cek = 1;
            break;
          }
          pq.push({-hrg, {ty, tx}});
        }
      }
      if(cek) {
        break;
      }
    }
  }
  return 0;
}