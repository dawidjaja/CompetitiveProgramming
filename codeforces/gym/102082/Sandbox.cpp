#include <bits/stdc++.h>
#define pp 1000000007
using namespace std;

typedef vector<long long> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef vector<char> vc;
typedef vector<vc> vvc;

inline int popcount(int n) {return __builtin_popcount(n);}
inline long popcount(long  n) {return __builtin_popcountl(n);}
inline long long popcount(long long n) {return __builtin_popcountll(n);}

inline double cross(complex<double> a, complex<double> b) {
    return (conj(a) * b).imag();
}

pair<complex<double>, double> __centroid(vector<complex<double>> &points) {
    int n = points.size();
    auto centroid1 = (points[0] + points[n-2] + points[n-1]) / complex<double>(3, 0);
    auto area1 = abs(cross(points[0], points[n-2]) + cross(points[n-2], points[n-1]) + cross(points[n-1], points[0]));
    if (points.size() > 3) {
        points.pop_back();
        auto [centroid2, area2] = __centroid(points);
        return pair((centroid1 * area1 + centroid2 * area2)/(area1 + area2), area1 + area2);
    } else {
        return pair(centroid1, area1);
    }
}

complex<double> centroid(vector<complex<double>> points) {
    return __centroid(points).first;
}

int main() {
    iostream::sync_with_stdio(false), cin.tie(nullptr);
    string s1, s2; cin >> s1 >> s2;
    vi s1next0, s1next1, s2next0, s2next1;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '0') {
            int n = s1next0.size();
            for (int j = 0; j < i - n + 1; j++) {
                s1next0.push_back(i);
            }
        } else {
            int n = s1next1.size();
            for (int j = 0; j < i - n + 1; j++) {
                s1next1.push_back(i);
            }
        }
    }
    int temp = s1next0.size();
    for (int j = 0; j < s1.size() - temp + 1; j++) {
        s1next0.push_back(s1.size());
    }
    s1next0.push_back(s1.size());

    temp = s1next1.size();
    for (int j = 0; j < s1.size() - temp + 1; j++) {
        s1next1.push_back(s1.size());
    }
    s1next1.push_back(s1.size());

    for (int i = 0; i < s2.size(); i++) {
        if (s2[i] == '0') {
            int n = s2next0.size();
            for (int j = 0; j < i - n + 1; j++) {
                s2next0.push_back(i);
            }
        } else {
            int n = s2next1.size();
            for (int j = 0; j < i - n + 1; j++) {
                s2next1.push_back(i);
            }
        }
    }
    temp = s2next0.size();
    for (int j = 0; j < s2.size() - temp + 1; j++) {
        s2next0.push_back(s2.size());
    }
    s2next0.push_back(s2.size());

    temp = s2next1.size();
    for (int j = 0; j < s2.size() - temp + 1; j++) {
        s2next1.push_back(s2.size());
    }
    s2next1.push_back(s2.size());

    deque<pair<pair<int, int>, pair<int, pair<int, int>>>> dq;
    dq.emplace_back(pair(0, 0), pair(0, pair(0, 0)));
    vvb visited(s1.size() + 2, vb(s2.size() + 2, false));
    vvii parents(s1.size() + 2, vii(s2.size() + 2));
    vvi parent_edge(s1.size() + 2, vi(s2.size() + 2));
    while (!dq.empty()) {
        auto [parent, en] = dq.front();
        auto [edge, node] = en;
        auto [x, y] = node;
        dq.pop_front();
        if (visited[x][y]) continue;
        visited[x][y] = true;
        parent_edge[x][y] = edge;
        parents[x][y] = parent;
        if (x == s1.size() + 1 && y == s2.size() + 1) break;
        ii neighbour0(s1next0[x] + 1, s2next0[y] + 1);
        ii neighbour1(s1next1[x] + 1, s2next1[y] + 1);
        dq.emplace_back(node, pair(0, neighbour0));
        dq.emplace_back(node, pair(1, neighbour1));
    }

    string result;
    pair<int, int> node(s1.size() + 1, s2.size() + 1);
    while (parents[node.first][node.second] != node) {
        result.push_back(parent_edge[node.first][node.second] + '0');
        node = parents[node.first][node.second];
    }
    reverse(result.begin(), result.end());
    cout << result;
}