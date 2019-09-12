#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int t, n, x, cek;
vector <int> v[3];

int main() {
  scanf("%d", &t);
  for(int tc = 1; tc <= t; tc++) {
    scanf("%d", &n);
    v[0].clear();
    v[1].clear();
    cek = 0;
    for(int i = 0; i < n; i++) {
      scanf("%d", &x);
      v[i & 1].push_back(x);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    for(int i = 0; i < n - 1; i++) {
      // printf("-- %d %d --\n", v[0][(i + 1) / 2], v[1][i / 2]);
      if(i & 1) {
        if(v[0][(i + 1) / 2] < v[1][i / 2]) {
          cek = 1;
          printf("Case #%d: %d\n", tc, i);
          break;
        }
      } else {
        if(v[0][(i + 1) / 2] > v[1][i / 2]) {
          cek = 1;
          printf("Case #%d: %d\n", tc, i);
          break;
        } 
      }
    }
    if(!cek) {
      printf("Case #%d: OK\n", tc);
    }
  }
  return 0;
}