#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

int c, a;
vector <vector<int> > grid, vis;
queue<ppi> q;

int y[4], x[4];

pii tf(pii p, int i) {
    //printf("-- %d %d --\n", i, y[i]);
    return {p.fs + y[i], (p.sc + x[i] + a) % a};
}

int main() {

    y[0] = 0;
    y[1] = 0;
    y[2] = 1;
    y[3] = -1;

    x[0] = -1;
    x[1] = -2;
    x[2] = -1;
    x[3] = -1;

    scanf("%d%d", &c, &a);

    for (int i = 0; i < c; i++) {
        getchar();
        vector<int> v_tmp, tv;
        for (int j = 0; j < a; j++) {
            char cc = getchar();
            if (cc == 'M') {
                v_tmp.push_back(1);
            } else {
                v_tmp.push_back(0);
            }
            tv.push_back(0);
        }
        vis.push_back(tv);
        grid.push_back(v_tmp);
    }

    vis[0][0] = 1;
    q.push({{0, 0}, 0});


    while (q.size()) {
        pii cur = q.front().fs;
        int dis = q.front().sc;
        q.pop();
        
        //printf("-- %d %d -- %d\n", cur.fs, cur.sc, dis);
        
        for (int i = 0; i < 4; i++) {
            pii tmp = tf(cur, i);

            if (tmp.fs < 0) continue;
            //printf("tmp -> %d %d\n", tmp.fs, tmp.sc);

            if (tmp.fs == c) {
                printf("%d\n", dis + 1);
                return 0;
            }

            if (grid[tmp.fs][tmp.sc] == 0 && vis[tmp.fs][tmp.sc] == 0) {
                if (i >= 1 && grid[tmp.fs][(tmp.sc + 1) % a] == 1) {
                    continue;
                }
                vis[tmp.fs][tmp.sc] = 1;
                q.push({{tmp.fs, tmp.sc}, dis + 1});
            }
        }
    }
    printf("-1\n");
    return 0;
}
