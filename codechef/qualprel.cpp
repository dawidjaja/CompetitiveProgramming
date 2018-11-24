#include <algorithm>
#include <cstdio>

using namespace std;

int n, k, t, list[100005];

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", &list[i]);
        }
        sort(list, list + n, cmp);
        int tmp = k;
        while (tmp < n)
            if (list[tmp] == list[k - 1])
                tmp++;
            else 
                break;
        printf("%d\n", tmp);
    }
    return 0;
}
