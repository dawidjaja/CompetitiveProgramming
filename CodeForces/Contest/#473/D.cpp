#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>

using namespace std;

long long gde, n, list[100005], ada[100005], cek, b[100005];
vector <long long> v;
set <long long> se;

inline void sieve() {
  for(long long i = 2; i <= gde; i++) {
    if(ada[i] == 0) {
      v.push_back(i);
      se.insert(i);
      if(i * i >= gde) {
        continue;
      }
      for(long long j = i * i; j <= gde; j += i) {
        ada[j] = 1;
      }
    }
  }
}

int main() {
  gde = 100000;
  scanf("%lld", &n);
  for(long long i = 1; i <= n; i++) {
    scanf("%lld", &list[i]);
  }
  sieve();
  cek = 0;
  for(long long i = 1; i <= n; i++) {
    b[i] = list[i];
    long long vs = v.size();
    if(cek) {
      b[i] = *se.begin();
      // printf("-- %lld %lld --\n", i, b[i]);
      se.erase(se.begin());
    } else {
      for(long long j = 0; j < vs; j++) {
        if(list[i] == 1) {
          break;
        }
        if(v[j] > sqrt(list[i])) {
          if(se.count(list[i])) {
            se.erase(list[i]);
          } else {
            b[i] = *(lower_bound(se.begin(), se.end(), b[i]));
            se.erase(b[i]);
            cek = 1;
          }
          break;
        }
        long long awal = 1;
        int lala = 0;
        while(list[i] % v[j] == 0) {
          if(!se.count(v[j]) && awal) {
            b[i] = *(lower_bound(se.begin(), se.end(), b[i]));
            // printf("---- %lld %lld --\n", i, b[i]);
            se.erase(b[i]);
            lala = 1;
            cek = 1;
            break;
          }
          se.erase(v[j]);
          awal = 0;
          list[i] /= v[j];
        }
        if(lala) {
          break;
        }
      }
    }
  }
  for(long long i = 1; i <= n; i++) {
    if(i == n) {
      printf("%lld\n", b[i]);
      break; 
    }
    printf("%lld ", b[i]);
  }
  return 0;
}