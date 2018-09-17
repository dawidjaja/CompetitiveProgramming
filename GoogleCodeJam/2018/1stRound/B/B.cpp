#include <algorithm>
#include <cstdio>

using namespace std;

inline void tmbh() {
  tmp++;
  if(tmp == ans) {
    cnt++;
  } else if(tmp > ans) {
    ans = tmp;
    cnt = 1;
  }
}

int main() {
  scanf("%d", &tt);
  for(int tc = 1; tc <= tt; tc++) {
    scanf("%d", &s);
    for(int i = 1; i <= s; i++) {
      scanf("%d%d%d", &a, &b, &c);
      list[i] = {a + b, a - c};
    }
    l = 1; r = 0;
    ans = 0;
    tmp = 0;
    cnt = 0;
    p = list[1].fs;
    q = ud;
    while(r < n) {
      r++;
      if(list[r].fs == p){
        tmbh();
      } else if(q == ud) {
        tmbh();
        q = list[r].sc;
      } else if(list[r].sc == q) {
        tmbh();
      } else {
        
      }
    }
  }
  return 0;
}