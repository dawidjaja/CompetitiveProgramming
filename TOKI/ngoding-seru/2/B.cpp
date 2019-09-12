#include <bits/stdc++.h>

using namespace std;

int n, k, id, ans, lpair[505], m, vis[505], day;
vector <int> v[505];

bool findPair(int x) {
    //printf("-- %d %d\n", day, x);
    for (int i = 0; i < v[x].size(); i++) {
        if (vis[v[x][i]] == day) continue;
        vis[v[x][i]] = day;
        if (lpair[v[x][i]] == -1 || findPair(lpair[v[x][i]])) {
            lpair[v[x][i]] = x;
            return true;
        }
    }
    return false;
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            for (int kk = 0; kk < 3; kk++) {
                int x;
                scanf("%d", &x);
                v[id].push_back(x);
            }
            id++;
        }
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = -1;
        lpair[i] = -1;
    }
    ans = 0;
    for (int i = 0; i < id; i++) {
        day = i;
        if (findPair(i)) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
