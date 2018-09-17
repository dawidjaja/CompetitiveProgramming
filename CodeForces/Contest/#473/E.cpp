#include <algorithm>
#include <cstdio>

using namespace std;

long long n, ans, x, tmp;

int main() {
  scanf("%lld", &n);
  x = 2;
  while(true) {
    tmp = (n + (x / 2 - 1)) / x;
    tmp *= x / 2;
    if(tmp == 0) {
      break;
    } 
    ans += tmp;
    x *= 2;
  }
  printf("%lld\n", ans);
  return 0;
}