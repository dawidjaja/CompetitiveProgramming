#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define fs first
#define sc second
#define pii pair<int,int>
#define INF 1e9 + 7

using namespace std;

int n, m, s, t, a, b, ans, cek[1005][1005], kcl[3][1005];
vector<int> v[1005];
priority_queue <pii> pq;

void dfs(int skrg, int sblm, int ke, int jrk) {
  kcl[ke][skrg] = jrk;
  int vs = v[skrg].size();
  for(int i = 0; i < vs; i++) {
    if(jrk + 1 < kcl[ke][v[skrg][i]]) {
      dfs(v[skrg][i], skrg, ke, jrk + 1);
    }
  }
}

int main() {
  scanf("%d%d%d%d", &n, &m, &s, &t);
  for(int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    cek[a][b] = 1;
    cek[b][a] = 1;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) {
    kcl[0][i] = INF;
    kcl[1][i] = INF;
  }
  
  dfs(s, -1, 0, 0);
  dfs(t, -1, 1, 0);

  for(int i = 1; i <= n; i++) {
    for(int j = i + 1; j <= n; j++) {
      if(cek[i][j] == 0) {
        if(((kcl[0][i] + kcl[1][j] + 1) >= kcl[0][t]) && ((kcl[1][i] + kcl[0][j] + 1) >= kcl[1][s])) {
          ans++;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}