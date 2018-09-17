#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int tt, n, m, a, b, vis[1005], ke, ans, kiri[1005];
vector <int> v[1005];

inline int baca() {
  int temp = 0;
  char c;
  c = getchar_unlocked();
  while(c < '0' || c > '9') {
    c = getchar_unlocked();
  }
  while(c >= '0' && c <= '9') {
    temp = ((temp << 3) + (temp << 1));
    temp += c - '0';
    c = getchar_unlocked();
  }
  return temp;
}

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

int main() {
  tt = baca();
  for(int tc = 1; tc <= tt; tc++) {
    n = baca(); m = baca();
    for(int i = 1; i <= n; i++) {
      v[i].clear();
      kiri[i] = -1;
      vis[i] = 0;
    }

    for(int i = 1; i <= m; i++) {
      a = baca(); b = baca();
      v[a].push_back(b);
    }
    
    ans = n;
    for(int i = 1; i <= n; i++) {
      ke = i;
      if(cari(i)) {
        ans--;
      }
    }
    printf("Case %d: %d\n", tc, ans);
  }
  return 0;
}zZ