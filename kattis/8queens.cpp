#include <assert.h>
#include <algorithm>
#include <cstdio>
#include <queue>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int a[] = {0, 1, 1, 1, 0, -1, -1, -1};
int b[] = {1, 1, 0, -1, -1, -1, 0, 1};
char list[10][10];
queue<pii> q;

bool in(int y, int x) {
    if (0 <= y && y < 8 && 0 <= x && x < 8) {
        return true;
    }
    return false;
}

bool cek(int y, int x) {
    for (int i = 0; i < 8; i++) {
        int ty = y + a[i];
        int tx = x + b[i];
        while (in(ty, tx)) {
            if (list[ty][tx] == '*') {
                return false;
            }
            ty += a[i];
            tx += b[i];
        }
    }
    return true;
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            scanf("%c", &list[i][j]);
            if (list[i][j] == '*') {
                q.push({i, j});
            }
        }
        getchar();
    }
    if (q.size() != 8) {
        printf("invalid\n");
        return 0;
    }
    while (q.size()) {
        int y = q.front().fs;
        int x = q.front().sc;
        q.pop();
        if(!cek(y, x)) {
            printf("invalid\n");
            return 0;
        }
    }
    printf("valid\n");
}

