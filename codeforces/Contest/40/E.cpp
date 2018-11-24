#include <algorithm>
#include <cstdio>
#include <cmath>

#define eps 1e-12
#define fs first
#define sc second
#define pii pair<long long,long long>

using namespace std;

long long n, t, l, r, skrg;
double temp, v, ttl;
pii list[200005];

int main() {
  scanf("%lld%lld", &n, &t);
  for(long long i = 1; i <= n; i++) {
    scanf("%lld", &list[i].sc);
  }
  for(long long i = 1; i <= n; i++) {
    scanf("%lld", &list[i].fs);
  }
  sort(list + 1, list + 1 + n);

  for(long long i = 1; i <= n; i++) {
    ttl += list[i].fs * list[i].sc;
    v += list[i].sc;
  }

  temp = 1.0 * ttl / v;

  // printf("-- %lf, %lld %lld\n", temp, ttl, v);

  l = 1; r = n;
  while(abs(temp - t) >= eps && l <= r) {
    if(temp > t) {
      skrg = r--;
    } else {
      skrg = l++;
    }
    double x = 1.0 * (ttl - t * v) / (list[skrg].fs - t);
    if(x > list[skrg].sc) {
      x = list[skrg].sc;
    } 
    ttl -= x * list[skrg].fs;
    v -= x;
    temp = 1.0 * ttl / v;
  }

  if(l > r && abs(temp - t) >= eps) {
    double nol = 0;
    printf("%.6lf\n", nol);
    return 0;
  }

  printf("%.6lf\n", v);

  return 0;
}