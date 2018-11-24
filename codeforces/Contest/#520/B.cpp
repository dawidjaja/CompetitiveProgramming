#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

int n, ans;

int main() {
    scanf("%d", &n);
    if (n == 1) {
        printf("1 0\n");
        return 0;
    }
    int N = n;
    int cek = 0;
    int last = -1;
    int satu = 1;
    for (int i = 2; i <= N; i++) {
        int tmp = 0;
        if (n % i == 0) {
            satu *= i;
            while (n % i == 0) {
                n /= i;
                tmp++;
            }
            int loga = 0;
            if (last != -1 && tmp != last) {
                cek = 1;
            }
            last = tmp;
            int dua = 1;
            while (tmp > dua) {
                loga++;
                dua *= 2;
            }
            if (tmp != dua) {
                cek = 1;
            }
            ans = max(loga, ans);
        }
    }
    //printf("-- %d %d --\n", ans, cek);
    printf("%d %d\n", satu, (N == satu ? 0 : ans + cek));
    return 0;
}
