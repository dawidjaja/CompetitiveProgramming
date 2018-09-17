#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int tc, n, m, a, b, grup[1005], vis[1005];
vector <int> v[1005];
bool cek;
map <int,int> ada[1005];

bool dfs(int skrg, int sblm, int tipe) {
  // printf("-- %d %d %d --\n", skrg, sblm, tipe);
  grup[skrg] = tipe;
  int vs = v[skrg].size();
  vis[skrg] = 1;
  for(int i = 0; i < vs; i++) {
    if(v[skrg][i] != sblm) {
      if(grup[v[skrg][i]] == grup[skrg]) {
        return false;
      } else {
        if(vis[v[skrg][i]] == 0) {
          bool tmp = dfs(v[skrg][i], skrg, tipe ^ 3);
          if(!tmp) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

int main() {
  scanf("%d", &tc);
  while(tc--) {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
      v[i].clear();
      ada[i].clear();
      grup[i] = 0;
      vis[i] = 0;
    }
    for(int i = 1; i <= m; i++) {
      scanf("%d%d", &a, &b);
      ada[a][b] = 1;
      ada[b][a] = 1;
    }
    for(int i = 1; i <= n; i++) {
      for(int j = i + 1; j <= n; j++) {
        if(!ada[i].count(j)){ 
          v[i].push_back(j);
          v[j].push_back(i);
        }
      }
    }
    cek = true;
    for(int i = 1; i <= n; i++) {
      if(grup[i] == 0) {
        cek &= dfs(i, 0, 1);
      }
    }
    if(cek) {
      printf("YES\n");
    } else {
      printf("NO\n");
    }
  }
  return 0;
}