#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int r, c, dp[1005][1005], list[1005][1005], kiri[1005], kanan[1005], ans;

inline int itung(int y, int x) {
  return 2 * (dp[y][x] + (kanan[x] - kiri[x] + 1));
}

int main() {
  scanf("%d%d", &r, &c);
  for(int i = 1; i <= r; i++) {
    getchar();
    for(int j = 1; j <= c; j++) {
      list[i][j] = (getchar() == '.') ? 1 : 0;
    }
  }
  ans = 0;

  for(int i = 1; i <= r; i++) {

    vector <pii> v;
    int tmax = 0;
    v.push_back({-1, 0});

    for(int j = 1; j <= c; j++) {
      if(list[i][j] == 1) {
        dp[i][j] = dp[i - 1][j] + 1;
      } else {
        dp[i][j] = 0;
      }
      
      while(v.back().fs > dp[i][j]) {
        kanan[v.back().sc] = j - 1;
        v.pop_back();
      }
      kiri[j] = v.back().sc + 1;
      v.push_back({dp[i][j], j});
    }
    while(v.size()) {
      kanan[v.back().sc] = c;
      v.pop_back();
    }
    for(int j = 1; j <= c; j++) {
      // printf("-- %d %d --> %d %d --\n", i, j, kiri[j], kanan[j]);
      if(list[i][j] == 1) {
        tmax = max(tmax, itung(i, j));
      }
    }
    ans = max(tmax, ans);
  }
  // for(int i = 1; i <= r; i++) {
  //   for(int j = 1; j <= c; j++) {
  //     printf("%d", dp[i][j]);
  //   }
  //   printf("\n");
  // }
  printf("%d\n", ans - 1);
  return 0;
}