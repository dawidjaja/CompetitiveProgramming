#include <algorithm>
#include <cstdio>
#include <queue>
#include <map>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

int tc;

int main() {
    scanf("%d", &tc);
    while (tc--) {
        int n, k, ans;
        pii list[100005];
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &list[i].fs, &list[i].sc);
        }
        priority_queue <pii> pq;
        priority_queue <int> ki, ka;
        map <int,int> freq[2];
        freq[0].clear();
        freq[1].clear();
        while (ki.size()) ki.pop();
        while (ka.size()) ka.pop();
        while (pq.size()) pq.pop();
        sort(list, list + n);
        for (int i = 0; i < k; i++) {
            pq.push({-list[i].sc, list[i].fs});
            ki.push(list[i].fs);
            ka.push(-list[i].sc);
            freq[0][list[i].fs]++;
            freq[1][list[i].sc]++;
        }
        ans = max(0, -ka.top() - ki.top());
        for (int i = k; i < n; i++) {
            pq.push({-list[i].sc, list[i].fs});
            freq[0][list[i].fs]++;
            freq[1][list[i].sc]++;

            if (freq[0][list[i].fs] == 1) {
                ki.push(list[i].fs);
            }
            if (freq[1][list[i].sc] == 1) {
                ka.push(-list[i].sc);
            }

            pii tmp = pq.top();
            pq.pop();
            freq[0][tmp.sc]--;
            freq[1][-tmp.fs]--;

            while (freq[0][ki.top()] == 0) {
                ki.pop();
            }
            while (freq[1][-ka.top()] == 0) {
                ka.pop();
            }

            ans = max(ans, -ka.top() - ki.top());
        }
        printf("%d\n", ans);
    }
    return 0;
}
