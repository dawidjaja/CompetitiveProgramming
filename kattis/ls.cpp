#include <bits/stdc++.h>

using namespace std;

string p, s;
int n, a, b;

int main() {
    cin >> p;
    scanf("%d", &n);
    a = p.length();

    int star_back = 0;
    while (a >= 0 && p[a] == '*') {
        a--;
        star_back = 1;
    }

    for (int i = 0; i < n; i++) {
        cin >> s;
        b = s.length();
        int ptr = 0;
        int can = 1;
        for (int j = 0; j < a; j++) {
            int star = 0;
            while (j < a && p[j] == '*') {
                star = 1;
                j++;
            }
            if (star == 1) {
                if (j == a) {
                    ptr = b;
                    break;
                }
                while (ptr < b && s[ptr] != p[j]) {
                    ptr++;
                }
            }
            if (s[ptr] != p[j]) {
                can = 0;
                break;
            }
            ptr++;
        }
        if (can == 1 && (star_back || ptr == b)) {
            cout << s << endl;
        }
    }
    return 0;
}
