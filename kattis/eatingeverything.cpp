#include <bits/stdc++.h>

using namespace std;

int n, m;
int child[500005];
double c[500005], opt[500005];
queue<int> q;
vector<int> par[500005];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &c[i]);
    opt[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    par[b].push_back(a);
    child[a]++;
  }
  for (int i = 0; i < n; i++) {
    if (child[i] == 0) {
      opt[i] = c[i];
      q.push(i);
    }
  }
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int i = 0; i < par[cur].size(); i++) {
      int p = par[cur][i];
      opt[p] = max(opt[p], max(opt[cur], c[p] + opt[cur] / 2));
      child[p]--;
      if (child[p] == 0) {
        q.push(p);
      }
    }
  }
  printf("%lf\n", opt[0]);
}