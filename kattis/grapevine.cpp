#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int n, m, d, skep[100005], heard[100005], vis[100005], ans;
vector<int> v[100005];
map<string, int> name;
queue<pii> q;

int main() {
    scanf("%d%d%d", &n, &m, &d);

    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        name[s] = i;
        skep[i] = x;
        if (x == 0) {
            heard[i] = 1;
        }
    }

    for (int i = 0; i < m; i++) {
        string s, t;
        cin >> s >> t;

        v[name[s]].push_back(name[t]);
        v[name[t]].push_back(name[s]);
    }

    string init;
    cin >> init;

    int st;

    st = name[init];
    q.push({st, 0});

    while (q.size()) {
        int cur = q.front().fs;
        int day = q.front().sc;
        if (day == d) {
            break;
        }
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            if (heard[v[cur][i]] == 0) {
                heard[v[cur][i]] = 1;
                ans++;
            }
            if (vis[v[cur][i]] == 0 && --skep[v[cur][i]] == 0) {
                q.push({v[cur][i], day + 1});
                vis[v[cur][i]] = 1;
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
