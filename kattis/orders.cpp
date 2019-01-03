#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int price[105], n, m, pos[30005], from[30005];

void update(int x) {
    for (int i = 1; i <= 30000; i++) {
        if (i - price[x] >= 0 && pos[i - price[x]] > 0) {
            pos[i] += pos[i - price[x]];
            from[i] = x;
        }
    }
}

int main() {
    scanf("%d", &n);
    pos[0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &price[i]);
        update(i);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int s;
        scanf("%d", &s);
        if (pos[s] == 1) {
            vector <int> ans;
            int tmp = s;
            while (tmp != 0) {
                ans.push_back(from[tmp]);
                tmp = tmp - price[from[tmp]];
            }
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                printf("%d", ans[i]);
                printf("%c", i == ans.size() - 1 ? '\n' : ' ');
            }
        } else if (pos[s] == 0) {
            printf("Impossible\n");
        } else {
            printf("Ambiguous\n");
        }
    }
    return 0;
}
