#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

string s;
int n, ptr, ans;

int main() {
  scanf("%d", &n);
  cin >> s;
  ptr = 0;
  while(ptr < n) {
    if(ptr == 0) {
      ptr++;
      ans++;
      continue;
    }
    if(ptr > n / 2) {
      ans += n - ptr;
      break;
    }
    int cek = 0;
    for(int i = 0; i < ptr; i++) {
      if(s[i] != s[i + ptr]) {
        cek = 1;
        break;
      }
    }
    if(cek) {
      ptr++;
    } else {
      ptr *= 2;
    }
    ans++;
  }
  printf("%d\n", ans);
  return 0;
}