#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int t, n, tmp;
string ans, s;

int main() {
  scanf("%d", &t);
  getchar();
  for(int tc = 1; tc <= t; ++ tc) {
    cin >> s;
    n = s.size();
    tmp = 0;
    ans = "";
    // cout << s;
    for(int i = 0; i < n; i++) {
      if(s[i] == '/') {
        if(tmp == 0) {
          continue;
        } else {
          ans += 'A' + tmp - 1;
          tmp = 0;
        }
      } else if(s[i] == '-') {
        // printf("--%d--\n", tmp);
        tmp *= 2;
        tmp++;
      } else if(s[i] == '.') {
        // printf("--%d--\n", tmp);
        tmp *= 2;
      } else if(s[i] == '#'){
        ans += ' ';
      }
    }
    printf("Case #%d: ", tc);
    cout << ans << endl;
  }
  return 0;
}