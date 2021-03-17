#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

string s;

int main() {

    cin >> s;

    int n = s.length();
    long long finans = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            for (int k = j; k < n; k += i) {
                long long ans = 1;
                int tlast = 1;
                char last;
                if (k == j) {
                    last = s[k];
                } else {
                    if (last == s[k]) {
                        tlast++;
                    } else {
                        ans *= tlast;
                        last = s[k];
                        tlast = 1;
                    }
                }
                ans *= tlast;
                finans = max(ans, finans);
            }
        }
    }
    printf("%lld\n", finans);

    return 0;
}
