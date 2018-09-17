#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define pii pair<long long,long long>
#define pip pair<long long,pii>

using namespace std;

long long p[100005], n, ans, a, b, c;
vector <pii> vt[5];
vector <pip> v;

long long par(long long x) {
  if(p[x] == x) {
    return x;
  } else {
    return p[x] = par(p[x]);
  }
}

int main() {
  scanf("%lld", &n);
  for(long long i = 1; i <= n; i++) {
    scanf("%lld%lld%lld", &a, &b, &c);
    vt[0].push_back({a, i});
    vt[1].push_back({b, i});
    vt[2].push_back({c, i});
    p[i] = i;
  }

  sort(vt[0].begin(), vt[0].end());
  sort(vt[1].begin(), vt[1].end());
  sort(vt[2].begin(), vt[2].end());
  for(long long i = 0; i < n - 1; i++) {
    v.push_back({abs(vt[0][i].fs - vt[0][i + 1].fs), {vt[0][i].sc, vt[0][i + 1].sc}});
    v.push_back({abs(vt[1][i].fs - vt[1][i + 1].fs), {vt[1][i].sc, vt[1][i + 1].sc}});
    v.push_back({abs(vt[2][i].fs - vt[2][i + 1].fs), {vt[2][i].sc, vt[2][i + 1].sc}});
  }
  sort(v.begin(), v.end());
  long long vs = v.size();
  for(long long i = 0; i < vs - 1; i++) {
    long long nilai = v[i].fs;
    long long a = v[i].sc.fs;
    long long b = v[i].sc.sc;
    if(par(a) != par(b)) {
      p[par(a)] = par(b);
      ans += nilai;
    }
  }
  printf("%lld\n", ans);
  return 0;
}