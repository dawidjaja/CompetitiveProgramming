#include <bits/stdc++.h>

using namespace std;

const long long INF = -10000000000;
long long n, num[100005], len[100005], from[100005], ans;
vector <long long> lis;
vector <long long> v_ans;

int binser(int l, int r, int x) {
    //printf("-- %d %d --\n", l, r);
    if (l == r) return l;
    int mid = (l + r) / 2 + 1;
    if (num[len[mid]] < num[x]) {
        return binser(mid, r, x);
    } else {
        return binser(l, mid - 1, x);
    }
}

int main() {
    while (scanf("%lld", &n) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%lld", &num[i]);
        }
        for (long long i = 0; i <= n; i++) {
            len[i] = -1;
            from[i] = -1;
        }

        len[0] = n;

        ans = 0;
        num[n] = -INF;
        for (long long i = 0; i < n; i++) {
            long long pjg = binser(0, ans, i);
            //printf("%lld dari %lld\n", i, pjg);
            len[pjg + 1] = i;
            from[i] = len[pjg];
            ans = max(ans, pjg + 1);
        }

        v_ans.clear();
        long long tmp = len[ans];
        //printf("tmp awal => %lld\n", tmp);
        while (tmp != n) {
            //printf("tmp %lld\n", tmp);
            v_ans.push_back(tmp);
            tmp = from[tmp];
        }
        printf("%lld\n", (long long)v_ans.size());
        while (v_ans.size()) {
            printf("%lld", v_ans.back());
            if (v_ans.size() != 1) printf(" ");
            v_ans.pop_back();
        }
        printf("\n");
    }
    return 0;
}
