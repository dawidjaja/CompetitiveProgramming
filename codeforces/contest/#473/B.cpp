#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

long long list[100005], p[100005], x, a, b;
map <string, long long> idx;
string s;

long long par(long long x) {
  if(p[x] == x) {
    return x;
  } else {
    return p[x] = par(p[x]);
  }
}

int main() {
  long long n, k, m;
  scanf("%lld%lld%lld", &n, &k, &m);
  for(long long i = 1; i <= n; i++) {
    cin >> s;
    idx[s] = i;
  }
  for(long long i = 1; i <= n; i++) {
    scanf("%lld", &list[i]);
    p[i] = i;
  }
  for(long long i = 1; i <= k; i++) {
    scanf("%lld", &x);
    for(long long j = 1; j <= x; j++) {
      scanf("%lld", &b);
      if(j != 1) {
        list[par(a)] = min(list[par(a)], list[par(b)]);
        p[par(b)] = par(a);
      }
      a = b;
    }
  }
  long long ans = 0;
  for(long long i = 1; i <= m; i++) {
    cin >> s;
    ans += list[par(idx[s])];
  }
  printf("%lld\n", ans);
  return 0;
}