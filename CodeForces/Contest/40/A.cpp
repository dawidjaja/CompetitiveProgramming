#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

string s;

int main() {
  int n;
  int ans = 0;
  scanf("%d", &n);
  cin >> s;
  for(int i = 0; i < s.size() - 1; ++i) {
    if(s[i] != s[i + 1]) {
      ans++;
      i++;
    }
  }
  printf("%d\n", s.size() - ans);
  return 0;
}