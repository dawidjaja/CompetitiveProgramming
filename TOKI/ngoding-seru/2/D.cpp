#include <bits/stdc++.h>

using namespace std;

int park[2005], ans, n, cppark[2005];

int findK() {
    for (int i = 0; i < n; i++) 
        if (park[i] == 2) return i;
}

int findBlue(int x) {
    for (int i = x + 1; i < n; i++) 
        if (park[i] == 1) return i;
    return -1;
}

int findSpace(int x) {
    for (int i = x + 1; i < n; i++) 
        if (park[i] == 0) return i;
    return -1;
}

int findSpaceBlue(int x) {
    for (int i = x - 1; i >= 0; i--) 
        if (park[i] == 0) return i;
    return -1;
}

int getAns() {
    int ans = 0;
    while (true) {
        int x = findK();
        if (findBlue(x) == -1) break;
        int sp = findSpace(x);
        int b, bsp;
        if (sp == -1) {
            b = findBlue(x);
            bsp = findSpaceBlue(b);
            park[bsp] = 1;
            park[b] = 0;
            ans += b - bsp;
            if (findBlue(x) == -1) break;
            park[x] = 0;
            park[b] = 2;
            ans += b - x;
        } else {
            park[sp] = 2;
            park[x] = 0;
            ans += sp - x;
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        char c = getchar();
        if (c == 'B') park[i] = cppark[i] = 1;
        if (c == '-') park[i] = cppark[i] = 0;
        if (c == 'K') park[i] = cppark[i] = 2;
    }
    ans = 0;
    ans = getAns();
    int finAns = ans;
    for (int i = 0; i < n; i++) {
        park[i] = cppark[i];
    }
    for (int i = 0; i < n / 2; i++) {
        swap(park[i], park[n - i - 1]);
    }
    for (int i = 0; i < n; i++) {
        if (park[i] != 0) park[i] = 3 - park[i];
    }
    ans = getAns();
    printf("-- %d %d --\n", finAns, ans);
    finAns = min(ans, finAns);
    printf("%d\n", finAns);
}
