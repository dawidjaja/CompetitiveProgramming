#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

long long t, d, list[105], n, tmp, def, ans, blkg;
string s;
vector <long long> v;

int main() {
  scanf("%lld", &t);
  for(long long tc = 1; tc <= t; tc++) {
    scanf("%lld", &d);
    cin >> s;
    n = s.size();
    tmp = 1;
    def = 0;
    for(long long i = 0; i < n; i++) {
      if(s[i] == 'S') {
        def += tmp;
        list[i] = tmp;
      } else {
        tmp *= 2;
        list[i] = 0;
        v.push_back(i);
      }
    }
    ans = 0;
    blkg = n - 1;
    while(v.size()) {
      if(d >= def) {
        break;
      } else {
        for(long long i = v.back(); i < blkg; i++) {
          if(d >= def) {
            break;
          } else {
            def -= list[i + 1] / 2;
            list[i] = list[i + 1] / 2;
            ans++;
          }
        }
        blkg--;
      }
      v.pop_back();
    }
    if(d >= def) {
      printf("Case #%lld: %lld\n", tc, ans);
    } else {
      printf("Case #%lld: IMPOSSIBLE\n", tc);
    }
  }
  return 0;
}