#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>

using namespace std;

long long n, ans, pngkt, tmp, dp[105], cek[100005];

int main() {
  scanf("%lld", &n);
  for(long long i = 2; i <= n; i++) {
    ans += n - 1;
    if(cek[i]) {
      continue;
    }
    tmp = i * i;
    pngkt = 2;
    while(tmp <= n) {
      cek[tmp] = 1;
      if(dp[pngkt] == 0) {
        set<int> seet;
        for(long long j = 1; j < pngkt; j++) {
          for(int k = n; k > 1; k--) {
            long long tmp = j * k;
            if(tmp % pngkt == 0) {
              seet.insert(tmp / pngkt);
              // printf("-- %lld %lld\n", pngkt, tmp / pngkt);
            }
          }
        }
        seet.erase(1);
        dp[pngkt] = seet.size();
        // for(auto it = seet.begin(); it != seet.end(); ++it) {
        //   printf("set %d\n", *it);
        // }
        // printf("__ %lld %lld\n", pngkt, dp[pngkt]);
      }
      ans -= dp[pngkt];
      tmp *= i;
      pngkt++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}