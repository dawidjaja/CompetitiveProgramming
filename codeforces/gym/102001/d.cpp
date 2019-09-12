#include <bits/stdc++.h>

using namespace std;

int r, c, ans;
char grid[505][505];

int main() {
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) {
        getchar();
        for (int j = 0; j < c; j++) {
            grid[i][j] = getchar();
        }
    }

    if (r == 1 || c == 1) {
        if (r == 1) {
            for (int i = 1; i < c - 1; i++) {
                if (grid[0][i] == '.') {
                    ans++;
                }
            }
        } else {
            for (int i = 1; i < r - 1; i++) {
                if (grid[i][0] == '.') {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
        return 0;
    }

    if (r == 2 || c == 2) {
        if (r == 2) {
            for (int i = 1; i < c - 1; i++) {
                if (grid[0][i] == '.' && grid[1][i] == '.') {
                    ans++;
                }
            }
        } else {
            for (int i = 1; i < r - 1; i++) {
                if (grid[i][0] == '.' && grid[i][1] == '.') {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
        return 0;
    }
    
    for (int i = 1; i < r - 1; i++) {
        for (int j = 1; j < c - 1; j++) {
            if (grid[i][j] != '#') {
                ans++;
            }
        }
    }
    int exist = 0;
    for (int i = 1; i < r - 1; i++) {
        if (grid[i][0] == '#' || grid[i][c - 1] == '#') {
            exist = 1;
        }
    }
    for (int i = 1; i < c - 1; i++) {
        if (grid[0][i] == '#' || grid[r - 1][i] == '#') {
            exist = 1;
        }
    }
    if (!exist) {
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
