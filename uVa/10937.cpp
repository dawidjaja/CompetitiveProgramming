#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
const double PI = acos(-1);
const double EPS = 1e-7;
 
#define PB push_back
#define MP make_pair
#define FOR(_i, _from, _to) for (int (_i) = (_from), (_batas) = (_to); (_i) <= (_batas); (_i)++)
#define REP(_i, _n) for (int (_i) = 0, (_batas) = (_n); (_i) < (_batas); (_i)++)
#define SZ(_x) ((int)(_x).size())
 
const int MAX_RC = 50;
const int MAX_TREASURE = 10;
 
struct Pos {
  int r, c;
};
 
struct QNode {
  int r, c, mask;
};
 
const int nDir = 4;
const int dr[] = {0, 0, -1, 1};
const int dc[] = {-1, 1, 0, 0};
const int INF = 1000111000;
 
int R, C;
char petaa[MAX_RC + 5][MAX_RC + 5];
bool canVisit[MAX_RC + 5][MAX_RC + 5];
int isTreasure[MAX_RC + 5][MAX_RC + 5];
bool visited[MAX_RC + 5][MAX_RC + 5][1100];
int main() {
  while(scanf("%d %d", &R, &C) && !(R == 0 && C == 0)) {
    REP(i, R) scanf("%s", petaa[i]);
 
    REP(r, R) REP(c, C) canVisit[r][c] = true;
 
    int nTreasure = 0;
    Pos st; 
 
    memset(isTreasure, -1, sizeof isTreasure);
    REP(r, R) REP(c, C) {
      if (petaa[r][c] == '~') petaa[r][c] = '#';
      if (petaa[r][c] == '@') {
        petaa[r][c] = '.';
        st = (Pos) {r, c};
      }
 
      if (petaa[r][c] == '!') {
        petaa[r][c] = '.';
        isTreasure[r][c] = nTreasure++;
      }
 
      if (petaa[r][c] == '#') canVisit[r][c] = false;
      if (petaa[r][c] == '*') {
        FOR(rr, max(0, r-1), min(R-1, r+1))
          FOR(cc, max(0, c-1), min(C-1, c+1))
            canVisit[rr][cc] = false;
      }
    }
 
    queue<QNode> q;
    q.push((QNode) {st.r, st.c, 0});
 
    memset(visited, 0, sizeof visited);
    int ans = INF;
    for (int step = 0; !q.empty(); step++) {
      REP(_, SZ(q)) {
        QNode node = q.front();
        q.pop();
        if (!canVisit[node.r][node.c]) continue;
        if (visited[node.r][node.c][node.mask]) continue;
        visited[node.r][node.c][node.mask] = true;
 
        if ((node.mask == (1 << nTreasure) - 1) && (node.r == st.r && node.c == st.c)) {
          ans = step;
          while(!q.empty()) q.pop();
          break;
        }
 
        REP(i, nDir) {
          QNode nxt;
          nxt.r = node.r + dr[i];
          nxt.c = node.c + dc[i];
          nxt.mask = node.mask;
          if (nxt.r < 0 || nxt.r >= R || nxt.c < 0 || nxt.c >= C || !canVisit[nxt.r][nxt.c]) continue;
          if (isTreasure[nxt.r][nxt.c] != -1) {
            nxt.mask |= 1 << isTreasure[nxt.r][nxt.c];
          }
          q.push(nxt);
        }
      }
    }
 
    if (ans >= INF) puts("-1");
    else printf("%d\n", ans);
  }
 
	return 0;
}
 
