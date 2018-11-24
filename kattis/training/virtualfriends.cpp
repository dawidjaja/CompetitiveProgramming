#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

map<string, int> names;
int p[200005], f[200005], n, t;

int par(int x) {
    if (x == p[x]) return x;
    return p[x] = par(p[x]);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        names.clear();
        int ctr = 0;
        for (int i = 0; i <= 2 * n; i++) {
            p[i] = i;
            f[i] = 1;
        }
        for (int i = 0; i < n; i++) {
            char a[10], b[10];
            scanf("%s%s", a, b);
            if (!names.count(a)) names[a] = ++ctr;
            if (!names.count(b)) names[b] = ++ctr;
            int x = names[a];
            int y = names[b];
            if (par(x) == par(y)) {
                printf("%d\n", f[par(x)]);
            } else {
                f[par(x)] += f[par(y)];
                p[par(y)] = par(x);
                printf("%d\n", f[par(x)]);
            }
        }
    }
}
