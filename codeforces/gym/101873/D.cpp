#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

char a[50], dum[50], b[50];
map <string, int> cmprs;
int ctr, dist[205][205], n, m;
const int INF = 1000000005;
vector <int> v[205];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%s%s%s%s%s", a, dum, dum, dum, b);
        if (!cmprs.count(a)) {
            cmprs[a] = ++ctr;
        }
        if (!cmprs.count(b)) {
            cmprs[b] = ++ctr;
        }
        v[cmprs[a]].push_back(cmprs[b]);
    }
    for (int i = 1; i <= ctr; i++) {
        for (int j = 1; j <= ctr; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
        for (int j = 0; j < v[i].size(); j++) {
            dist[i][v[i][j]] = 1;
        }
    }
    for (int k = 1; k <= ctr; k++)
        for (int i = 1; i <= ctr; i++)
            for (int j = 1; j <= ctr; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    while (m--) {
        scanf("%s%s%s%s%s", a, dum, dum, dum, b);
        if (!cmprs.count(a) || !cmprs.count(b)) {
            printf("Pants on Fire\n");
            continue;
        }
        int x = cmprs[a];
        int y = cmprs[b];
        if (dist[x][y] > 0 && dist[x][y] < INF) {
            printf("Fact\n");
            continue;
        }
        if (dist[y][x] > 0 && dist[y][x] < INF) {
            printf("Alternative Fact\n");
            continue;
        }
        printf("Pants on Fire\n");
    }
    return 0;
}
