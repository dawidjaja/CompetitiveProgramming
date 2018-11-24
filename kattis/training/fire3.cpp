#include <algorithm>
#include <cstdio>
#include <queue>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>

using namespace std;

int r, c, list[1005][1005], a[4], b[4];
char letter;
queue <ppi> q;

int main() {
    scanf("%d%d", &r, &c);
    a[0] = b[1] = 1;
    a[2] = b[3] = -1;
    for (int i = 0; i <= r + 1; i++) {
        for (int j = 0; j <= c + 1; j++) {
            list[i][j] = 2;
        }
    }
    pii start;
    for (int i = 1; i <= r; i++) {
        getchar();
        for (int j = 1; j <= c; j++) {
            scanf("%c", &letter);
            if (letter == '#') {
                list[i][j] = 1;
            } else if (letter == '.') {
                list[i][j] = 0;
            } else if (letter == 'J') {
                start = {i, j};
                list[i][j] = 1;
            } else if (letter == 'F') {
                q.push({{i, j}, -1});
                list[i][j] = 1;
            }

        }
    }
    q.push({start, 0});
    while (q.size()) {
        int y = q.front().fs.fs;
        int x = q.front().fs.sc;
        int s = q.front().sc;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (list[y + a[i]][x + b[i]] == 2 && s != -1) {
                printf("%d\n", s + 1);
                return 0;
            }
            if (list[y + a[i]][x + b[i]] == 0) {
                int newS = s == -1 ? -1 : s + 1;
                list[y + a[i]][x + b[i]] = 1;
                q.push({{y + a[i], x + b[i]}, newS});
            }
        }
    }
    printf("IMPOSSIBLE\n");
    return 0;
}
