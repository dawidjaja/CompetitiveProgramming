#include <bits/stdc++.h>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

set<int> st;
int stree[2][1000005], lazy[2][1000005], n, a, b, c, d;
pii seg[100005];
map<int,int> com;

int update(int idx, int cur, int l, int r, int a, int b, int x) {
    if (b < l || r < a) {
        return stree[idx][cur] + lazy[idx][cur];
    } 
    if (a <= l && r <= b) {
        lazy[idx][cur] += x;
        return stree[idx][cur] + lazy[idx][cur];
    }

    int mid = (l + r) >> 1;
    int ta = update(idx, cur * 2, l, mid, a, b, x);
    int tb = update(idx, cur * 2 + 1, mid + 1, r, a, b, x);

    stree[idx][cur] = max(ta, tb);
    //printf("-- %d %d - %d %d - %d %d --\n", idx, cur, l, r, stree[idx][cur], lazy[idx][cur]);
    return stree[idx][cur] + lazy[idx][cur];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        seg[i] = {d, b};
        st.insert(d);
        st.insert(b);
    }


    int ctr = 0;
    for (auto it = st.begin(); it != st.end(); it++) {
        com[*it] = ctr++;
    }

    for (int i = 0; i < n; i++) {
        seg[i] = {com[seg[i].fs], com[seg[i].sc]};
    }

    sort(seg, seg + n);

    for (int i = 0; i < n; i++) {
        //printf("-- step %d update %d %d\n", i, seg[i].fs, seg[i].sc);

        //printf("ans -> %d\n", 
        update(0, 1, 0, 200000, seg[i].fs, seg[i].sc, 1);
        //);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        //printf("-- ganti %d update %d %d\n", i, seg[i].fs, seg[i].sc);
        //printf("ans = %d\n", 
        update(0, 1, 0, 200000, seg[i].fs, seg[i].sc, -1);
            //);
        //printf("-- ganti %d update %d %d\n", i, seg[i].fs, seg[i].sc);
        //printf("ans = %d\n", 
        update(1, 1, 0, 200000, seg[i].fs, seg[i].sc, 1);
            //);
        int ta, tb;
        ta = stree[0][1] + lazy[0][1];
        tb = stree[1][1] + lazy[1][1];
        //printf("%d --> %d %d\n", i, ta, tb);
        ans = max(ans, ta + tb);
    }
    printf("%d\n", ans);
}
