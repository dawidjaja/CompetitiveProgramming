#include <bits/stdc++.h>

#define fs first
#define sc second

using namespace std;

pair <int, string> number[10005];
set <string> history;
int tc, n;

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            cin >> number[i].sc;
            number[i].fs = number[i].sc.length();
        }
        history.clear();
        sort(number, number + n);
        bool can = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < number[i].fs; j++) {
                string s = number[i].sc.substr(0, j + 1);
                if (history.count(s)) {
                    can = false;
                    break;
                }
            }
            if (!can) break;
            //cout << "history >> " << number[i].sc << endl;
            history.insert(number[i].sc);
        }
        if (can) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
