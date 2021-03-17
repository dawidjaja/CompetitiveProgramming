#include<bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;
    int n; scanf("%d", &n);
    char str[128];
    for (int i = 0; i < n; i++) {
        int x; scanf("%7d", &x);
        scanf("%[^\n]", str);
        if (x > 1e6) continue;
        s.insert(x); 
    }
    for (int i = 0; i < 1e6 + 7; i++)
        if (s.count(i) == 0) {
            printf("%d\n", i);
            return 0;
        }
}
