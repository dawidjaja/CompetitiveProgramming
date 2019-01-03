#include <bits/stdc++.h>

using namespace std;

int num[10];

int main() {
    char s[10];
    scanf("%d%d%d", &num[0], &num[1], &num[2]);
    sort(num, num + 3);
    getchar();
    scanf("%s", s);
    for (int i = 0; i < 3; i++) {
        printf("%d", num[s[i] - 'A']);
        printf("%c", i == 2 ? '\n' : ' ');
    }
}
