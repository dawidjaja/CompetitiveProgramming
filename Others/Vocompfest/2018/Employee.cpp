#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int day[105], with[105], now, n, m, x, a, ans;
vector <int> v[105];

bool ada(int skrg) {
  day[skrg] = now;
  // printf("%d %d\n", now, skrg);
  int vs = v[skrg].size();
  for(int i = 0; i < vs; i++) {
    if(with[v[skrg][i]] == -1 || (day[with[v[skrg][i]]] != now && ada(with[v[skrg][i]]))) {
      with[v[skrg][i]] = skrg;
      return true;
    }
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= m; i++) {
    scanf("%d", &x);
    while(x--) {
      scanf("%d", &a);
      v[i].push_back(a);
    }
    day[i] = -1;
  }
  for(int i = 1; i <= n; i++) {
    with[i] = -1;
  }
  for(int i = 1; i <= m; i++) {
    now = i;
    if(ada(i)) {
      ans++;
    }
  }
  if(ans == min(n, m)) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  return 0;
}