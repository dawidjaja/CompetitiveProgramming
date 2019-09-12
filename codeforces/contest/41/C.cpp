#include <algorithm>
#include <cstdio>

using namespace std;

int n, a, list[10], ans;

int main() {
  scanf("%d", &n);
  for(int t = 1; t <= 4; t++) {
    for(int i = 1; i <= n * n; i++) {
      scanf("%1d", &a);
      if(a == (i & 1)) {
        list[t]++;
      }
    }
  }
  sort(list + 1, list + 5);
  ans = list[1] + list[2] + n * n * 2 - list[3] - list[4];
  printf("%d\n", ans);
  return 0;
}