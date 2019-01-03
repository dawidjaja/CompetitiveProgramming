#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

pii queen[5005];
int n;

bool hit(pii a, pii b) {
    if (a.fs == b.fs || a.sc == b.sc ||
        (abs(a.fs - b.fs) == abs(a.sc - b.sc))) {
        return true;
    }
    return false;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &queen[i].fs, &queen[i].sc);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (hit(queen[i], queen[j])) {
                printf("INCORRECT\n");
                return 0;
            }
        }
    }
    printf("CORRECT\n");
    return 0;
}
