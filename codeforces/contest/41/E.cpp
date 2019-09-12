#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define pii pair<long long,long long>

using namespace std;

long long n, bit[200005], list[200005], ptr, ans;
pii arr[200005];

bool cmp(pii a, pii b) { 
  return a > b;
}

inline void tmbh(long long x) {
  for(long long i = x; i <= n; i += (i & -i)) {
    bit[i]++;
  }
}

inline long long itung(long long x) {
  long long ret = 0;
  for(long long i = x; i > 0; i -= (i & -i)) {
    ret += bit[i];
  }
  return ret;
}

int main() {
  scanf("%lld", &n);
  for(long long i = 1; i <= n; i++) {
    scanf("%lld", &list[i]);
    arr[i] = {list[i], i};
    // if(list[i] >= i) {
    //   ans--;
    // }
  }
  sort(arr + 1, arr + 1 + n, cmp);
  ptr = 1;
  for(long long i = 1; i <= n; i++) {
    while(ptr <= n && arr[ptr].fs >= n - i + 1) {
      tmbh(arr[ptr].sc);
      ptr++;
    }
    ans += itung(min(n - i, list[n - i + 1]));
  }
  printf("%lld\n", ans);
  return 0;
}