#include <bits/stdc++.h>

#define fs first
#define sc second
#define pdd pair<double,double>
#define pdi pair<double,int>
#define ppi pair<pdd,int>

using namespace std;

int main() {
    double a, b;
    while (scanf("%lf%lf", &a, &b) != EOF) {

        int n;
        cin >> n;
        vector<ppi> seg(n);

        for (int i = 0; i < n; i++) {
            cin >> seg[i].fs.fs >> seg[i].fs.sc;
            seg[i].sc = i;
        }

        sort(seg.begin(), seg.end());

        int ptr = 0;
        priority_queue <pdi> pq;

        while (ptr < n && seg[ptr].fs.fs <= a) {
            pq.push({seg[ptr].fs.sc, seg[ptr].sc});
            ptr++;
        }

        double cur = a;
        vector<int> ans;

        while (pq.size()) {
            double r = pq.top().fs;
            int idx = pq.top().sc;
            pq.pop();
            //printf("-- %lf %d --\n", r, idx);
            if (r >= cur) {
                cur = r;
                ans.push_back(idx);
                if (cur >= b) break;
            }
            while (ptr < n && seg[ptr].fs.fs <= cur) {
                pq.push({seg[ptr].fs.sc, seg[ptr].sc});
                ptr++;
            }
        }
        if (cur < b || ans.size() == 0) {
            printf("impossible\n");
        } else {
            printf("%d\n", ans.size());
            for (int i = 0; i < ans.size(); i++) {
                printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}
