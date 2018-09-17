#include <algorithm>
#include <cstdio>

using namespace std;

long long n, x, kali, ke, ans, dpn, blkg, dp[10000005], vis[10000005], skrg;

int main() {
  scanf("%lld", &n);
  for(long long i = 1; i <= n; i++) {
    scanf("%lld", &x);
    vis[x] = 1;
    kali = 1;
    ke = 1;
    while(x >= kali) {
      long long tmp = x;
      blkg = tmp % kali;
      dpn = tmp / kali;
      skrg = dpn % 10;
      dpn /= 10;
      dpn *= kali * 10;
      tmp = dpn + blkg;
      for(long long j = 0; j < 10; j++) {
        // printf("-- %lld %lld --\n", x, tmp);
        if(vis[tmp]) {
          dp[x] = max(dp[x], dp[tmp] + abs(skrg - j));
        }
        ans = max(dp[x], ans);
        tmp += kali;
      }
      ke++;
      kali *= 10;
    }
    // printf("%lld\n", ans);
  }
  printf("%lld\n", ans);
  return 0;
}