#include <algorithm>
#include <cstdio>

using namespace std;

int n, list[5005];
char c;

int main() {
    while (scanf("%c", &c) != EOF) {
        if (c == '(') {
            list[n++] = 1;
        } else if (c == ')'){
            list[n++] = -1;
        }
    }
    int ttl = 0;
    bool can = 1;
    for (int i = 0; i < n; i++) {
        ttl += list[i];
        if (ttl < 0) can = false;
    }
    if (can && ttl == 0) {
        printf("possible\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        list[i] *= -1;
        if (i != 0) {
            list[i - 1] *= -1;
        }
        int ttl = 0;
        bool can = true;
        for (int i = 0; i < n; i++) {
            ttl += list[i];
            if (ttl < 0) can = false;
        }
        if (can && ttl == 0) {
            printf("possible\n");
            return 0;
        }
    }
    printf("impossible\n");
    return 0;
}
