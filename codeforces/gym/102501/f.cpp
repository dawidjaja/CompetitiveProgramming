#include<bits/stdc++.h>
using namespace std;

int main() {
    int nq; scanf("%d", &nq);
    long long area = 0;
    while(nq--) {
        long long sub = 0;
        int n; scanf("%d", &n);
        vector<int> x(n), y(n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &x[i], &y[i]);
        for (int i = 0; i < n; i++) {
            sub += 1LL * x[i] * y[(i + 1) % n];
            sub -= 1LL * y[i] * x[(i + 1) % n];
        }
        area += abs(sub);
    }
    printf("%lld\n", area / 2);
}
