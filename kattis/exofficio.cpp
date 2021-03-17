#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, c;
    scanf("%d%d", &r, &c);

    for (int i = 0; i < 2 * c; i++) {
        printf("%c", (i & 1) ? '_' : ' ');
    }
    printf("\n");
    if (r != 1 && r % 2 == 1 && c % 2 == 0) {
        for (int i = 0; i < r; i++) {
            if (i == r / 2) {
                printf("|");
                for (int j = 1; j < 2 * c; j++) {
                    printf(" ");
                }
                printf("|");
            } else {
                for (int j = 0 ; j < 2 * c + 1; j++) {
                    printf("%c", (j & 1) ? (i == r - 1 ? '_' : ' ') : '|');
                }
            }
            printf("\n");
        }
    } else {

        for (int i = 0; i < r - 1; i++) {
            printf("|");
            for (int j = 0; j < c / 2; j++) {
                printf("_ ");
            }
            printf(" ");
            for (int j = 0; j < (c - 1) / 2; j++) {
                printf(" _");
            }
            printf("|\n");
        }
        printf("|");
        for (int j = 0; j < c - 1; j++) {
            printf("_ ");
        }
        printf("_|\n");
    }
    return 0;
}
