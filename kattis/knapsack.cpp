#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>
#define ppi pair<pii,int>
using namespace std;

int n, m, knap[2005][2005], from[2005][2005], maks, tmp;
ppi item[2005];
double c;

bool cmp(ppi a, ppi b) {
    return a.fs.sc > b.fs.sc;
}

int main() {
    while (scanf("%lf%d", &c, &n) != EOF) {
        int m = floor(c);
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                knap[i][j] = -1;
                from[i][j] = -1;
            }
            knap[i][0] = 0;
            from[i][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &item[i].fs.fs, &item[i].fs.sc);
            item[i].sc = i - 1;
        }
        sort(item + 1, item + n + 1, cmp);

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 0; j--) {
                knap[i][j] = knap[i - 1][j];
                from[i][j] = 1;
                //printf("-- %d %d\n", i, j);
                if (j - item[i].fs.sc >= 0 && knap[i - 1][j - item[i].fs.sc] != -1
                        && knap[i - 1][j - item[i].fs.sc] + item[i].fs.fs > knap[i][j]) {
                    //printf("-- %d %d go\n", i, j);
                    knap[i][j] = knap[i - 1][j - item[i].fs.sc] + item[i].fs.fs;
                    from[i][j] = 2;
                }
            }
        }

        vector<int> ans;
        tmp = m;
        int lvl = n;
        while (tmp != 0 && lvl >= 0) {
            //printf("%d %d %d\n", lvl, tmp, from[lvl][tmp]);
            if (from[lvl][tmp] == 2) {
                ans.push_back(item[lvl].sc);
                tmp -= item[lvl].fs.sc;
            }
            lvl--;
        }
        printf("%d\n", (int)ans.size());
        while (ans.size()) {
            printf("%d", ans.back());
            printf("%c", ans.size() == 1 ? '\n' : ' ');
            //if (ans.size() != 1) printf(" ");
            ans.pop_back();
        }
        //printf("\n");
    }
}

