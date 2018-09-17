#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

string s;
long long n, tmp, x, q, a, b, l, r, hes[100005], pngkt[100005];

bool cek(long long a, long long b, long long pjg) {
  long long ta = (hes[a] - (hes[a + pjg] * pngkt[pjg]));
  long long tb = (hes[b] - (hes[b + pjg] * pngkt[pjg]));
  if(ta == tb) {
    return true;
  } else {
    return false;
  }
} 

int main() {
  cin >> s;
  n = s.size();
  x = 53;
  pngkt[0] = 1;
  for(long long i = 1; i <= n; i++) {
    pngkt[i] = pngkt[i - 1] * x;
  }
  tmp = 0;
  for(long long i = n - 1; i >= 0; i--) {
    tmp *= x;
    if('A' <= s[i] && s[i] <= 'Z') {
      tmp += s[i] - 'A';
    } else {
      tmp += s[i] - 'a' + 26;
    }
    hes[i] = tmp;
  }
  // for(long long i = 0; i < n; i++) {
  //   printf("-- %lld --> %lld --\n", i, hes[i]);
  // }
  scanf("%lld", &q);
  while(q--) {
    scanf("%lld%lld", &a, &b);
    l = 0;
    r = n - b   ;
    while(l < r) {
      long long mid = ((l + r) >> 1) + 1;
      // printf("-- %lld %lld >> %lld -\n", l, r, mid);
      if(cek(a, b, mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    printf("%lld\n", l);
  }
  return 0;
}