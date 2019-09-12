#include <algorithm>
#include <cstdio>

using namespace std;

long long n, k, x, list[100005], ans, tmp, tans;

int main() {
  scanf("%lld%lld", &n, &k);
  for(long long i = 1; i <= n; i++) {
    scanf("%lld", &list[i]);
  }
  for(long long i = 1; i <= n; i++) {
    scanf("%lld", &x);
    ans += list[i] * x;
    list[i] *= 1 - x;
  }
  for(long long i = 1; i <= k; i++) {
    tmp += list[i];
  }
  tans = max(tmp, tans);
  for(long long i = 1; i <= n - k; i++) {
    tmp -= list[i];
    tmp += list[i + k];
    tans = max(tmp, tans);
  }
  printf("%lld\n", ans + tans);
  return 0;
}