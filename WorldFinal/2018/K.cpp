#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    ctr[a]++;
    ctr[b]++;
  }
  for(int i = 0; i < n; i++) {
    v.push_back({ctr[i], i});
  }
  return 0;
}