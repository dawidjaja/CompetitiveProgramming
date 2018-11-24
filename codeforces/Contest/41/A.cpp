#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, list[1005], a, ans;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; i++) {
    scanf("%d", &a);
    list[a]++;
  }
  ans = list[1];
  for(int i = 1; i <= n; i++) {
    ans = min(ans, list[i]);
  }
  printf("%d\n", ans);
  return 0;
}