#include <algorithm>
#include <cstdio>
#include <queue>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int a[5], b[5], sol, ans[1005][1005], tc, c, r;
char list[1005][1005];
queue <pii> q;

bool cek(int a, int b) {
    if (a < 0 || a >= r || b < 0 || b >= c) {
        return true;
    }
    return false;
}

void process(int y, int x) {
    if (list[y][x] == '@') {
        for (int i = 0; i < 4; i++) {
            if (cek(y + a[i], x + b[i])) {
                sol = ans[y][x] + 1;
                return;
            } else {
                if (list[y + a[i]][x + b[i]] == '.') {
                    list[y + a[i]][x + b[i]] = '@';
                    ans[y + a[i]][x + b[i]] = ans[y][x] + 1;
                    q.push({y + a[i], x + b[i]});
                }
            }
        }
    } else {
        for (int i = 0; i < 4; i++) {
            if (!cek(y + a[i], x + b[i]) && (list[y + a[i]][x + b[i]] == '.'
                || list[y + a[i]][x + b[i]] == '@')) {
                q.push({y + a[i], x + b[i]});
                list[y + a[i]][x + b[i]] = '*';
            }
        }
    }
}

int main() {
    scanf("%d", &tc);
    a[0] = b[1] = 1;
    a[2] = b[3] = -1;
    while (tc--) {
        scanf("%d%d", &c, &r);
        sol = -1;
        while (q.size()) q.pop();
        for (int i = 0; i < r; i++) {
            getchar();
            for (int j = 0; j < c; j++) {
                ans[i][j] = 0;
                list[i][j] = getchar();
                if (list[i][j] == '@') {
                    q.push({i, j});
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (list[i][j] == '*') {
                    q.push({i, j});
                }
            }
        }
        while (q.size()) {
            process(q.front().fs, q.front().sc);
            q.pop();
            if (sol != -1) {
                printf("%d\n", sol);
                break;
            }
        }
        if (sol == -1) {
            printf("IMPOSSIBLE\n");
        }
    }
}
