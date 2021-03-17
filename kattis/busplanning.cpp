#include <bits/stdc++.h>

using namespace std;

#define fs first
#define sc second

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;
typedef vector<int> vi;

bool isClique(int mask, vi &AL) {
    int full_mask = mask;
    int original_mask = mask;
    while (mask) {
        int lsone = mask & -mask;
        full_mask &= AL[__builtin_ctz(lsone)];
        mask -= lsone;
    }
    return full_mask == original_mask;
}

void printMask(int mask, vector<string> &names) {
    while (mask) {
        int lsone = mask & -mask;
        cout << names[__builtin_ctz(lsone)] << ' ';
        mask -= lsone;
    }
    cout << endl;
}

int main() {
    int n, k, c;
    scanf("%d%d%d", &n, &k, &c);

    getchar();
    vector<string> names(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    unordered_map<string, int> name_to_string;
    
    for (auto &name : names) name_to_string[name] = name_to_string.size();

    int full_mask = (1 << n) - 1;
    vector<int> AL(n, full_mask);
    for (int i = 0; i < k; i++) {
        string name1, name2;
        cin >> name1 >> name2;
        int i1 = name_to_string[name1];
        int i2 = name_to_string[name2];
        AL[i1] &= ~(1 << i2);
        AL[i2] &= ~(1 << i1);
    }

    vi memo(1 << n, INT_MAX);
    vi ancestor(1 << n);
    for (int mask = 1; mask <= full_mask; mask++) {
        if (__builtin_popcount(mask) <= c && isClique(mask, AL)) {
            memo[mask] = 1;
            ancestor[mask] = mask;
        } else {
            int max_mask = 1 << ( 31 - __builtin_clz(mask));

            for (int sub = mask & -mask; sub < max_mask; sub = (sub - mask) & mask) {
                if (memo[sub] == 1) {
                    if (1 + memo[mask - sub] < memo[mask]) {
                        memo[mask] = 1 + memo[mask - sub];
                        ancestor[mask] = sub;
                    }
                }
            }
        }
    }
    cout << memo[full_mask] << endl;
    auto mask = full_mask;
    while (mask) {
        auto sub = ancestor[mask];
        mask -= sub;
        printMask(sub, names);
    }
    return 0;
}
