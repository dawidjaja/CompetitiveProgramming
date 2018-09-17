#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector <int> v[505], suka[505], ga[505], rute;
queue <int> q;
int tipe[505], cap[505][505], temp, n, sblm[505], n1, n2;
char c;

inline void bikin(int a, int b) {
//  printf("-- %d %d --\n", a, b);
  v[a].push_back(b);
  v[b].push_back(a);
  cap[a][b] = 1;
  cap[b][a] = 0;
}

inline void jalan() {
  rute.push_back(n+1);
  while(sblm[rute.back()] != -2) {
    rute.push_back(sblm[rute.back()]);
  }
  return;
}

inline bool SP() {
  while(q.size()) {
    q.pop();
  }
  rute.clear();
  for(int i = 1; i <= n+1; i++) {
    sblm[i] = -1;
  }
  sblm[0] = -2;
  q.push(0);
  while(q.size()) {
    int skrg = q.front();
    q.pop();
    for(int i = 0; i < v[skrg].size(); i++) {
      if(cap[skrg][v[skrg][i]] > 0 && sblm[v[skrg][i]] == -1) {
        sblm[v[skrg][i]] = skrg;
        if(v[skrg][i] == n+1) {
          jalan();
          return true;
        }
        q.push(v[skrg][i]);
      }
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n1, &n2);
  scanf("%d", &n);
  for(int i = 1; i <= n; i++) {
    while(scanf("%c", &c) && (c != 'A' && c != 'B'));
    tipe[i] = c - 'A';
    while(scanf("%d", &temp) && temp != -1) {
      suka[i].push_back(temp);
    }
    while(scanf("%d", &temp) && temp != -1) {
      ga[i].push_back(temp);
    }
    sort(suka[i].begin(), suka[i].end());
    sort(ga[i].begin(), ga[i].end());
  }
  for(int i = 1; i <= n; i++) {
    if(tipe[i]) {
      bikin(i, n+1);
    } else {
      bikin(0, i);
      for(int j = 1; j <= n; j++) {
        if(tipe[j] != tipe[i]) {
          int a, b;
          a = 0;
          b = 0;
          int cek = 0;
          while(a < suka[i].size() && b < ga[j].size()){
            if(suka[i][a] == ga[j][b]) {
              cek = 1;
              break;
            }
            if(suka[i][a] < ga[j][b]) {
              a++;
            } else {
              b++;
            }
          }
          a = 0;
          b = 0;
          while(a < suka[j].size() && b < ga[i].size()){
            if(suka[j][a] == ga[i][b]) {
              cek = 1;
              break;
            }
            if(suka[j][a] < ga[i][b]) {
              a++;
            } else {
              b++;
            }
          }
          if(cek == 1) {
            bikin(i, j);
          }
        }
      }
    }
  }
  int ans = n;
  while(SP()) {
    int temp;
    temp = rute.back();
    while(rute.size()) {
      cap[temp][rute.back()]--;
      cap[rute.back()][temp]++;
      temp = rute.back();
      rute.pop_back();
    }
    ans--;
  }
  printf("%d\n", ans);
  return 0;
}
