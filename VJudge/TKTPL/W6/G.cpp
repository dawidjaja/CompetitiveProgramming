#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

string s;
char dpn;
int n, a, b, ans;

int main() {
  cin >> s;
  s = '2' + s + '2';
  n = s.size();
  dpn = s[(n - 1) / 2];
  
  for(int i = (n - 1) / 2 - 1; i >= 0; i--) {
    if(s[i] != dpn) {
      a = i + 1;
      break;
    }
  }
  for(int i = (n + 1) / 2; i < n; i++) {
    if(s[i] != dpn) {
      b = i - 1;
      break;
    }
  }
  ans = min(n - a - 1, b);
  printf("%d\n", ans);
  return 0;
}