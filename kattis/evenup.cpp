#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int n, list[100005];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        if (v.empty() || (((v.back() + list[i]) & 1) == 1)) {
            v.push_back(list[i]);
        } else {
            v.pop_back();
        }
    }
    printf("%d\n", v.size());
    return 0;
}
