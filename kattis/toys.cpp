#include <bits/stdc++.h>

using namespace std;

int n, k;

int f(int n, int k) {
    if (n == 1) return 0;
    return (f(n - 1, k) + k) % n;
}

int main() {
    scanf("%d%d", &n, &k);
    printf("%d\n", f(n, k));
    return 0;
}
