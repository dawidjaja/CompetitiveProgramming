#include <bits/stdc++.h>

using namespace std;

int k;
char x[2005], y[2005];
int main() {
    scanf("%d", &k);
    getchar();
    scanf("%s", x);
    scanf("%s", y);

    vector <int> ans;
    int lena = strlen(x);
    int lenb = strlen(y);
    int a = 0;
    int b = 0;
    a++; b++;
    a = a % lena;
    b = b % lenb;
    int start_k = k;
    if (x[0] != y[0]) {
        ans.push_back(0);
        printf("0\n");
        k--;
        if (k == 0) return 0;
    }
    int timer = 1;
    while (a != 0 || b != 0) {
        if (x[a] != y[b]) {
            printf("%d\n", timer);
            ans.push_back(timer);
            k--;
            if (k == 0) return 0;
        }
        a++; b++;
        a = a % lena;
        b = b % lenb;
        timer++;
    }
    if (start_k == k) {
        while (k--)
            printf("-1\n");
        return 0;
    }
    int over = timer;
    int ptr = 0;
    while (k--) {
        printf("%d\n", ans[ptr++] + over);
        ptr = ptr % ans.size();
        if (ptr == 0) {
            over += timer;
        }
    }
    return 0;
}
