#include <bits/stdc++.h>

using namespace std;

int S, l, n;

set<string> animals;
map<string, int> idx;
vector<int> w;
vector<string> anim;

bitset<205> init[205];

vector<int> split(vector<int> &cur) {
    if (cur.size() <= 1)
        return cur;

    /*
    printf("start \n");
    for (int i = 0; i < cur.size(); i++) {
        printf("%d ", cur[i]);
    }
    printf("\nend\n");
    */

    auto mid = cur.begin() + (cur.size() / 2);
    vector<int> tl(cur.begin(), mid);
    vector<int> tr(mid, cur.end());

    vector<int> l = split(tl), r = split(tr);
    vector<bitset<205> > suf(l.size());
    for (int i = l.size() - 1; i >= 0; i--) {
        if (i == l.size() - 1) {
            suf[i] = init[l[i]];
        } else {
            suf[i] = suf[i + 1] & init[l[i]];
        }
    }

    vector<int> ret;
    int lptr = 0;
    for (int i = 0; i < r.size(); i++) {
        while (lptr < l.size() && 
                (l[lptr] < r[i] || suf[lptr][r[i]] == 0)) {
            ret.push_back(l[lptr++]);
        }
        ret.push_back(r[i]);
    }

    while (lptr < l.size()) {
        ret.push_back(l[lptr++]);
    }

    
    /*
    printf("ini lll\n");
    for (int i = 0; i < l.size(); i++) {
        printf("%d ", l[i]);
    }
    printf("\nini rrr\n");
    for (int i = 0; i < r.size(); i++) {
        printf("%d ", r[i]);
    }
    printf("\n----\n");
    for (int i = 0; i < ret.size(); i++) {
        printf("%d ", ret[i]);
    }
    printf("\n------------\n");
    */

    return ret;
}

void printAnimal(int x) {
    cout << anim[x];
}

void update(int a, int b) {
    init[b][a] = 1;
    init[a][b] = 1;
}

int main() {
    scanf("%d%d%d", &S, &l, &n);

    getchar();
    for (int i = 0; i < S; i++) {
        string s; cin >> s;
        animals.insert(s);
    }

    int ctr = 0;
    for (auto it: animals) {
        anim.push_back(it);
        idx[it] = ctr++;
    }

    for (int i = 0; i < l; i++) {
        string a, b;
        cin >> a >> b;

        update(idx[a], idx[b]);
    }
    for (int i = 0; i < S; i++) {
        update(i, i);
    }

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        w.push_back(idx[s]);
    }

    /*
    for (int i = 0; i < w.size(); i++) {
        printf("%d ", w[i]);
    }
    printf("\n");
    */

    vector<int> ans = split(w);
    assert(ans.size() == w.size());
    for (int i = 0; i < ans.size(); i++) {
        printAnimal(ans[i]);
        if (i == ans.size() - 1) {
            cout << endl;
        } else {
            cout << ' ';
        }
    }
    return 0;
}
