#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int num(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    return c - 'a' + 10;
}

bool can(string a, string b, string c, int x) {
    if (x == 1) {
        for (int i = 0; i < a.length(); i++) 
            if (a[i] != '1') return false;
        for (int i = 0; i < b.length(); i++)
            if (b[i] != '1') return false;
        for (int i = 0; i < c.length(); i++)
            if (c[i] != '1') return false;
        return true;
    }
    for (int i = 0; i < a.length(); i++)
        if (num(a[i]) >= x) return false;
    for (int i = 0; i < b.length(); i++)
        if (num(b[i]) >= x) return false;
    for (int i = 0; i < c.length(); i++)
        if (num(c[i]) >= x) return false;
    return true;
}

int conv(string a, int base) {
    if (base == 1) return a.length();
    int ret = 0;
    for (int i = 0; i < a.length(); i++) {
        ret *= base;
        ret += num(a[i]);
    }
    return ret;
}

char ch(int x) {
    if (1 <= x && x <= 9) return '0' + x;
    if (x == 36) return '0';
    return 'a' + x - 10;
}

string x, y, z;
char op;
int tc;

int main() {
    scanf("%d", &tc);
    while (tc--) {
        //scanf("%s %c %s = %s", x, op, y, z);
        cin >> x >> op >> y;
        getchar();
        getchar();
        getchar();
        cin >> z;
        int wrong = 0;
        //cout << x << " + " << y << " + " << z << endl;
        for (int i = 1; i <= 36; i++) {
            int a, b, c;
            if (can(x, y, z, i)) {
                a = conv(x, i);
                b = conv(y, i);
                c = conv(z, i);
                //printf("-- %d %d -- %d\n", a, b, c);
                if (op == '+' && a + b == c) {
                    printf("%c", ch(i));
                } else if (op == '-' && a - b == c) {
                    printf("%c", ch(i));
                } else if (op == '*' && a * b == c) {
                    printf("%c", ch(i));
                } else if (op == '/' && a == b * c) {
                    printf("%c", ch(i));
                } else {
                    wrong++;
                }
            } else {
                wrong++;
            }
        }
        if (wrong == 36) {
            printf("invalid");
        }
        printf("\n");
    }
    return 0;
}
