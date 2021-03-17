#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> v[2];
    set<int> ans;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v[0].push_back(x);
        ans.insert(v[0][i]);
    }

    int cur = 0;
    while (v[cur].size() > 1) {
        for (int i = 0; i < v[cur].size() - 1; i++) {
            int tmp = __gcd(v[cur][i], v[cur][i + 1]);
            v[cur ^ 1].push_back(tmp);
            //printf("-- %d %d --\n", i, tmp);
            ans.insert(tmp);
        }
        v[cur].clear();
        cur ^= 1;
        auto it = unique(v[cur].begin(), v[cur].end());
        v[cur].resize(distance(v[cur].begin(), it)); 
    }
    printf("%d\n", ans.size());
    return 0;
}
