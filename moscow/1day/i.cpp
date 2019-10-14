#include <bits/stdc++.h>

using namespace std;

int n, nol[2000005], st[2000005], p[2000005], tot[2000005];
vector <int> v[2000005];
queue<int> q;

bool check_par(int cur) {
    printf("check -> %d\n", cur);
    if (cur == 0 || cur == -1) {
        return false;
    }
    if (st[cur] == 0) {
        if (nol[p[cur]] == 0 && check_par(p[p[cur]])) {
            return true;
        } else {
            return false;
            //return check_par(p[p[cur]]);
        }
    } else {
        return true;
    }
}

void dfs(int cur, int x) {
    dp[cur] = x;
    for (int i = 0; i < v[cur].size(); i++) {
        dfs(v[cur][i], 1 - x);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        int x;
        scanf("%d", &x);
        v[x].push_back(i);
        p[i] = x;
    }

    p[0] = -1;
    p[1] = 0;
    for (int i = 1; i <= n; i++) {
        if (v[i].size() == 0) {
            st[i] = 0;
            q.push(i);
        }
    }

    dfs(1);
    while (q.size()) {
        int cur = q.front();
        q.pop();

        tot[p[cur]]++;
        if (st[cur] == 0) {
            nol[p[cur]]++;
        }
        if (tot[p[cur]] == v[p[cur]].size()) {
            st[p[cur]] = (nol[p[cur]] != 0) ? 1 : 0;
            q.push(p[cur]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (st[i] != 1) {
            int tmp = check_par(i);
            printf("-- %d -- \n", tmp);
            if (tmp) {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}
