#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

string s;
long long n, r, x, hes[3][100005], pngkt[100005], ans;

long long itung(long long dpn, long long pjg, long long idx) {
  // printf("-- %lld %lld %lld\n", dpn, pjg, idx);
  if(pjg == 0) {
    return 0;
  }
  long long tmp;
  if(idx == 0) {
    if(dpn == 0) {
      tmp = hes[idx][dpn + pjg - 1] - (0 * pngkt[pjg]);
    } else {
      tmp = hes[idx][dpn + pjg - 1] - (hes[idx][dpn - 1] * pngkt[pjg]);
    }
  } else {
    tmp = (hes[idx][dpn] - (hes[idx][dpn + pjg] * pngkt[pjg]));
  }
  // printf("%lld %lld %lld --> %lld\n", dpn, pjg, idx, tmp);
  return tmp;
}

int main() {
  x = 53;
  pngkt[0] = 1;
  for(long long i = 1; i <= 100001; i++) {
    pngkt[i] = pngkt[i - 1] * x;
  }

  while (getline(cin, s)) {
    n = s.size();
    long long kali = 0;
    for(long long i = 0; i < n; i++) {
      kali *= x;
      if('A' <= s[i] && s[i] <= 'Z') {
        kali += s[i] - 'A';
      } else {
        kali += s[i] - 'a' + 26;
      }
      hes[0][i] = kali;
    }
    kali = 0;
    hes[1][n] = 0;
    for(long long i = n - 1; i >= 0; i--) {
      kali *= x;
      if('A' <= s[i] && s[i] <= 'Z') {
        kali += s[i] - 'A';
      } else {
        kali += s[i] - 'a' + 26;
      }
      hes[1][i] = kali;
    }
    
    // for(long long i = 0; i < n; i++) {
    //   printf("-- %lld --> %lld && %lld --\n", i, hes[0LL][i], hes[1LL][i]);
    // }

    ans = n;
    for(long long i = 0; i < n; i++) {
      long long tmp = n - i;
      long long pjg  = tmp / 2;
      // printf("-------- %lld ---------\n", i);
      if(itung(i, pjg, 0) == itung(n - pjg, pjg, 1)) {
        ans = i;
        break;
      }
      // printf("-------- %lld ---------\n\n", i);
    }
    cout << s;
    for(long long i = ans - 1; i >= 0; i--) {
      printf("%c", s[i]);
    }
    cout << endl;
  }
  return 0;
}