#include<bits/stdc++.h>
using namespace std;

typedef bitset<256> bs;

vector<int> ms(vector<int> v) {
    vector<int> ll(v.begin(), v.begin() + v.size() / 2);
    vector<int> rr(v.begin() + v.size() / 2, v.end());
    vector<int> sl = ms(l), sr = ms(r);

    vector<int> res;
    vector<bs> suf(sl.size());
    for (int rp = 0; rp < sr.size(); rp++) {
        while (lp < sl.size() & k
        res.eb(sr[rp])
    }
}

int main() {
}
