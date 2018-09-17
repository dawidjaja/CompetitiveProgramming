#include <algorithm>
#include <cstdio>

using namespace std;

void dfs(string skrg) {

}

int main() {
  ctr = 1;
  ke = 0;
  while (true) {
    cin >> s;
    bb = s[s.length() - 1];
    dd = s[0];
    tnd[idx] = {'', ''};
    if(dd == ',') {
      s = substr(1, s.length() - 1);
      tnd[idx].fs = ',';
    } else if(dd == '.') {
      s = substr(1, s.length() - 1);
      tnd[idx].fs = '.';
    }
    if(bb == ',') {
      s = substr(0, s.length() - 1);
      tnd[idx].sc = ',';
    } else if(bb == '.') {
      s = substr(0, s.length() - 1);
      tnd[idx].sc = '.';
    }
    
    if(!kata.find(s)) {
      kata[s] = ke++;
    }
    kalimat.push_back(kata[s]);
    if(dd == ',') {
      koma[kata[s]].fs = 1;
    }
    if(bb == ',') {
      koma[kata[s]].sc = 1;
    }
  }
  int vs = v.size();
  for(int i = 0; i < ke; i++) {
    if(vis[i] == 0) {
      dfs(i, -1);
    }
  }
  return 0;
}