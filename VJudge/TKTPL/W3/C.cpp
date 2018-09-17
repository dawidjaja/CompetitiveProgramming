#include <algorithm>
#include <cstdio>

using namespace std;

bool masuk(int x, int y) {
  if(1 <= x && x <= n && 1 <= y && y <= m) {
    return true;
  }
  return false;
}

void dfs(int x, int y) {
  vis[x][y] = ctr;
  for(int i = 1; i <= 4; i++) {
    int ta, tb;
    ta = x + a[i];
    tb = y + b[i];
    if(masuk(ta, tb)) {
      dfs(ta, tb);
    }
  }
}

int main() {

  a[1] = b[2] = 1;
  a[3] = b[4] = -1;

  scanf("%d%d%d", &n, &m, &q);
  for(int i = 1; i <= q; i++) {
    scanf("%d%d%d%d", &list[i].fs.fs, &list[i].fs.sc, &list[i].sc.fs, &list[i].sc.sc);
    for(int j = list[i].fs.fs; j <= list[i].fs.sc; j++) {
      for(int k = list[i].sc.fs; k <= list[i].sc.sc; k++) {
        vis[j][k]++;
      }
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= m; j++) {
      if(vis[i][j] == 0) {
        ctr++;
        p[ctr] = ctr;
        dfs(i, j);
      }
    }
  }
  next = ctr + 1;

  ans.push_back(ctr);
  for(int i = n; i >= 1; i--) {
    for(int j = list[i].fs.fs; j <= list[i].fs.sc; j++) {
      for(int k = list[i].sc.fs; k <= list[i].sc.sc; k++) {
        vis[j][k]--;
        if(vis[j][k] == 0) {
          for(int l = 1; l <= 4; l++) {
            int ta, tb;
            vector <int> vt;
            ta = j + a[l];
            tb = k + b[l];
            if(masuk(ta, tb) && vis[ta][tb] == 0) {
              vt.push_back()
            }
          }
        }
      }
    }
  }
  return 0;
}