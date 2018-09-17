#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> v[1005];
int item[4][1005], r, c, n, ans, ke, kiri[1005], vis[1005], a, b, cek;

bool cari(int skrg) {
  int vs = v[skrg].size();
  for(int i = 0; i < vs; i++) {
    if(vis[v[skrg][i]] != ke) {
      vis[v[skrg][i]] = ke;
      if(kiri[v[skrg][i]] == -1 || cari(kiri[v[skrg][i]])) {
        kiri[v[skrg][i]] = skrg;
        return true;
      }
    }
  }
  return false;
}

void dfs(int skrg) {
  // printf(" -- %d -- \n", skrg   );
  int vs = v[skrg].size();
  item[1][skrg] = 1;
  for(int i = 0; i < vs; i++) {
    if(item[2][v[skrg][i]] == 0 && kiri[v[skrg][i]] != skrg && kiri[v[skrg][i]] != -1) {
      item[2][v[skrg][i]] = 1;
      dfs(kiri[v[skrg][i]]);
    }
  }
}

int main() {
  scanf("%d%d%d", &r, &c, &n);
  while(r != 0 && c != 0 && n != 0) {
    for(int i = 1; i <= r; i++) {
      v[i].clear();
    }
    for(int i = 1; i <= c; i++) {
      kiri[i] = -1;
      vis[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
      scanf("%d%d", &a, &b);
      v[a].push_back(b);
    }
    ans = 0;
    for(int i = 1; i <= r; i++) {
      ke = i;
      if(cari(i)) {
        ans++;
      }
    }
    for(int i = 1; i <= r; i++) {
      item[1][i] = 0;
    }
    for(int i = 1; i <= c; i++) {
      item[2][i] = 0;
      item[1][kiri[i]] = 2;
    }

    for(int i = 1; i <= r; i++) {
      if(item[1][i] == 0) {
        dfs(i);
      }
    }
    printf("%d", ans);
    for(int i = 1; i <= r; i++) {
      if(item[1][i] != 1) {
        printf(" r%d", i);
      }
    }
    for(int i = 1; i <= c; i++) {
      if(item[2][i] == 1) {
        printf(" c%d", i);
      }
    }
    printf("\n");
    scanf("%d%d%d", &r, &c, &n);
  }
  return 0;
}