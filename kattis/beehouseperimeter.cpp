#include <algorithm>
#include <cstdio>
#include <vector>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int r, k, n;
vector <pii> v[125005];

inline void init() {
    /*
       5     6
    4     x     1
       3     2 
    */
    for (int i = 1; i <= r; i++) {
        int cur = i;
        for (int j = r; j <= r + i; j++) {
            int diff = (j >= 2 * r - 1 ? 4 * r - 3 - j : j);
            v[cur].push_back({3, cur + diff});
            v[cur + diff].push_back({6, cur});
            cur += diff;
        }
        cur = i;
        for (int j = r + 1; j <= r + r - i + 2; j++) {
            int diff = (j >= 2 * r ? 4 * r - j - 1 : j);
            v[cur].push_back({2, cur + diff});
            v[cur + diff].push_back({5, cur});
            cur += diff;
        }
    }
    int tmp = r;
    for (int i = 1; i <= r; i++) {
        int cur = tmp;
        if (i != 1) {
            for (int j = r + i - 1; j <= r + r; j++) {
                int diff = (j >= 2 * r - 1 ? 4 * r - 3 - j : j);
                v[cur].push_back({3, cur + diff});
                v[cur + diff].push_back({6, cur});
                cur += diff;
            }
        }
        tmp += r + i;
    }
    tmp = 4;
    int last;
    for (int i = 1; i < r; i++) {
        v[i].push_back({1, i + 1});
        v[i + 1].push_back({4, i});
    }
    for (int i = 2; i <= r; i++) {
        int cur = tmp;
        for (int j = r + r - i + 2; j >= r; j--) {
            int diff = (j >= 2 * r ? 4 * r - j - 1 : j);
            v[cur].push_back({2, cur + diff});
            v[cur + diff].push_back({5, cur});
            cur += diff;
        }
        cur = tmp;
        for (int j = 1; j <= r + i - 2; j++) {
            v[cur].push_back({1, cur + 1});
            v[cur + 1].push_back({4, cur});
            cur++;
        }
        tmp += r - 1 + i;
        last = cur + 1;
    }
    int cur = last;
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < 2 * r - i - 1; j++) {
            //printf("%d %d, %d - %d %d\n", i, j, cur, cur + diff, diff);
            v[cur].push_back({1, cur + 1});
            v[cur + 1].push_back({4, cur});
            cur++;
        }
        cur++;
    }
}

int main() {
    scanf("%d%d", &r, &k);
    n = r * r * r - (r - 1) * (r - 1) * (r - 1);
    init();
    /*
    for (int i = 1; i <= n; i++) {
        printf("%d --> ", i);
        for (int j = 0; j < v[i].size(); j++) {
            printf("(%d, %d) ", v[i][j].fs, v[i][j].sc);
        }
        printf("\n");
    }
    */
    return 0;
}
