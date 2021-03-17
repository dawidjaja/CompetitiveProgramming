include<bits/stdc++.h>
using namespace std;
#define M 1
typedef long long ll;

ll fp(ll a, ll b) {
    if (b <= 1) return b == 0 ? 1 : a % M;
    ll v = fp(a, b / 2);
    v = (v * v) % M;
    return (v * fp(a, b % 2)) % M;
}

ll inv(ll a) {
    return fp(a, m - 2);
}

int main() {
    int n; scanf("%d", &n);
    vector<ll> cat(n);
    cat[0] = 1; cat[1] = 1;

    for (int i = 2; i < n; i++) { 
        cat[i] = (2LL  * (2 * n + 1) * cat[i - 1]) % M;
        cat[i] = (cat[i] * inv(n + 2)) % M;
    }

    set<int> vals;
    pair<int, int> r(n);

    for(int i = 0; i < n; i++) {
    }
}
