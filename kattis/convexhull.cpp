#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>

#define fs first
#define sc second
#define pii pair<int,int>

using namespace std;

vector <pii> v[2], ch;
pii list[100005];
int n;

inline int read() {
    //printf("mulai read\n");
    int tmp = 0;
    bool neg = false;
    char c;
    c = getchar_unlocked();
    //printf("char pertama -> '%c'\n", c);
    while((c < '0' || c > '9') && c != '-') {
        c = getchar_unlocked();
    }
    while((c >= '0' && c <= '9') || c == '-') {
        //printf("char - '%c'\n", c);
        if (c != '-') {
            tmp *= 10;
            tmp += c - '0';
        } else {
            neg = true;
        }
        c = getchar_unlocked();
    }
    if (neg) tmp *= -1;
    return tmp;
}

bool concave(pii a, pii b, pii c) {
    long long dx = b.fs - a.fs;
    long long dy = b.sc - a.sc;
    long long ex = c.fs - b.fs;
    long long ey = c.sc - b.sc;
    if (dx * ey - dy * ex >= 0) {
        return true;
    }
    return false;
}

int dist(int a, int b) {
    int len = b - a;
    if (len < 0) len += n;
    return len;
}

int main() {
    ios_base::sync_with_stdio(false);
    while (true) {
        //n = read();
        cin >> n;
        //printf("-- %d --\n", n);
        if (n == 0) return 0;
        for (int i = 0; i < n; i++) {
            //list[i].fs = read();
            //list[i].sc = read();
            cin >> list[i].fs >> list[i].sc;
            //printf("list %d %d\n", list[i].fs, list[i].sc);
        }
        v[0].clear();
        v[1].clear();
        ch.clear();
        sort(list, list + n);
        for (int i = 0; i < n; i++) {
            if (v[0].size() && v[0][v[0].size() - 1] == list[i]) {
                continue;
            }
            if (v[0].size() < 2) {
                v[0].push_back(list[i]);
            } else {
                while (v[0].size() >= 2 && concave(v[0][v[0].size() - 2], v[0][v[0].size() - 1], list[i])) {
                    v[0].pop_back();
                }
                v[0].push_back(list[i]);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            if (v[1].size() && v[1][v[1].size() - 1] == list[i]) {
                continue;
            }
            if (v[1].size() < 2) {
                v[1].push_back(list[i]);
            } else {
                while (v[1].size() >= 2 && concave(v[1][v[1].size() - 2], v[1][v[1].size() - 1], list[i])) {
                    v[1].pop_back();
                }
                v[1].push_back(list[i]);
            }
        }
        for (int i = 0; i < v[0].size(); i++) {
            ch.push_back(v[0][i]);
            //printf("upper %d %d\n", v[0][i].fs, v[0][i].sc);
        }
        for (int i = 1; i < v[1].size() - 1; i++) {
            ch.push_back(v[1][i]);
            //printf("lower %d %d\n", v[1][i].fs, v[1][i].sc);
        }
        n = ch.size();
        printf("%d\n", n);
        for (int i = ch.size() - 1; i >= 0; i--) {
            printf("%d %d\n", ch[i].fs, ch[i].sc);
        }
    }
    return 0;
}


