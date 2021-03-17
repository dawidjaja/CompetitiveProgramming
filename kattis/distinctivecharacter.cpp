#include <bits/stdc++.h>

using namespace std;

int n, k, dist[1200000], ans;
vector <int> v[1200000];
queue <int> q;

int main() {
    scanf("%d%d", &n, &k);

    int MAX = 1 << k;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < k; j++) {
            v[i].push_back(i ^ (1 << j));
        }
        dist[i] = -1;
    }
    
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        for (int j = 0; j < k; j++) {
            int x;
            scanf("%1d", &x);
            tmp *= 2;
            tmp += x;
        }

        q.push(tmp);
        dist[tmp] = 0;
    }

    while (q.size()) {
        int cur = q.front();
        ans = cur;
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            if (dist[v[cur][i]] == -1) {
                dist[v[cur][i]] = dist[cur] + 1;
                q.push(v[cur][i]);
            }
        }
    }

    bitset<32> binans(ans);
    for (int i = k - 1; i >= 0; i--) {
        cout << binans[i];
    }
    cout << endl;
    return 0;
}
