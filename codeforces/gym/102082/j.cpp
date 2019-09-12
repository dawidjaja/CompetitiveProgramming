#include <bits/stdc++.h>

using namespace std;

int occ[100005], color[100005], edges[100005];
int n, q;
vector<int> lvl[20], v[100005];
set<int> nodes[100005];

void dfs(int cur, int prev, int lev) {

    occ[cur] = lvl[0].size();
    lvl[0].push_back(lev);

    for (int i = 0; i < v[cur].size(); i++) {
        if (prev != v[cur][i]) {
            dfs(v[cur][i], cur, lev + 1);
            lvl[0].push_back(lev);
        }
    }
}

int getMin(int a, int b) {
    int lev, tmp;
    lev = 0;
    tmp = 0;
    while (a + 2 * tmp + 1 <= b) {
        tmp *= 2;
        tmp++;
        lev++;
    }
    //printf("--- %d %d ---- %d %d ---\n", a, b, lvl[lev][a], lvl[lev][b - tmp]);
    return min(lvl[lev][a], lvl[lev][b - tmp]);
}

int count(int pos, int col) {
    auto l = nodes[col].lower_bound(pos);
    auto r = nodes[col].upper_bound(pos);
    int ret = 0;
    if (l == nodes[col].begin() && r == nodes[col].end()) {
        //cmn 1 node ato gaada
        return 0;
    } else if (l == nodes[col].begin()) {
        //printf("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb");
        ret = lvl[0][pos] - getMin(pos, *(r));
    } else if (r == nodes[col].end()) {
        //printf("cccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc");
        ret = lvl[0][pos] - getMin(*(--l), pos);
    } else {
        //printf("dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
        ret = lvl[0][pos] - max(getMin(*(--l), pos), getMin(pos, *(r)));
    }

    //printf("count -- %d %d %d = %d--\n", pos, col, lvl[0][pos], ret);
    return ret;
}

int getHLCA(int col) {
    if (nodes[col].size() == 0) {
        return -1;
    }
    auto dpn = nodes[col].begin();
    auto blkg = nodes[col].end();
    return getMin(*(dpn), *(--blkg));
}

void remove_node(int cur, int col) {
    int bef, aft;
    bef = getHLCA(col);

    edges[col] -= count(occ[cur], col);
    nodes[col].erase(occ[cur]);

    aft = getHLCA(col);
    //printf("-- removing -- %d => %d %d \n", col, bef, aft);
    if (bef != -1 && aft != -1) {
        edges[col] -= aft - bef;
    }
}

void insert_node(int cur, int col) {
    int bef, aft;
    bef = getHLCA(col);

    nodes[col].insert(occ[cur]);
    edges[col] += count(occ[cur], col);
    color[cur] = col;

    aft = getHLCA(col);
    //printf("-- inserting -- %d => %d %d \n", col, bef, aft);
    if (bef != -1 && aft != -1) {
        edges[col] += bef - aft;
    }
}

void print_set(int x) {
    for (auto it = nodes[x].begin(); it != nodes[x].end(); it++) {
        printf("%d ", *(it));
    }
    printf("\n");
}

int main() {
    scanf("%d", &n);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1, 0, 0);

    int diff = 1;
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i < lvl[j - 1].size(); i++) {
            lvl[j].push_back(lvl[j - 1][i]);
            if (i + diff < lvl[j - 1].size()) {
                lvl[j][i] = min(lvl[j - 1][i], lvl[j - 1][i + diff]);
            }
        }
        diff *= 2;
    }

    /*
    for (int i = 0; i < lvl[0].size(); i++) {
        printf("-- %d -- \n", lvl[0][i]);
    }
    */

    for (int i = 1; i <= n; i++) {
        color[i] = 0;
        nodes[0].insert(occ[i]);
    }
    edges[0] = n - 1;

    // baca warna + ganti
    for (int i = 1; i <= n; i++) {
        int c;
        scanf("%d", &c);

        remove_node(i, 0);
        insert_node(i, c);
        //printf("SET 0 - %d, ", edges[0]);
        //print_set(0);
        //printf("SET %d - %d, ", c, edges[c]);
        //print_set(c);
    }
    
    // query
    scanf("%d", &q);
    while (q--) {
        getchar();
        char cmd = getchar();
        if (cmd == 'Q') {
            int y;
            scanf("%d", &y);
            if (nodes[y].empty()) {
                printf("-1\n");
            } else {
                printf("%d\n", edges[y]);
            }
        } else if (cmd == 'U') {
            int x, y;
            scanf("%d%d", &x, &y);
            remove_node(x, color[x]);
            insert_node(x, y);
        }
    }
    return 0;
}
