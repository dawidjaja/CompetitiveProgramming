#include <bits/stdc++.h>

using namespace std;

string s;
map<char, int> freq;

int main() {
    cin >> s;
    int l = s.length();
    for (int i = 0; i < l; i++) {
        freq[s[i]]++;
    }
    int ans = 0;
    ans += freq['T'] * freq['T'];
    ans += freq['G'] * freq['G'];
    ans += freq['C'] * freq['C'];
    ans += 7 * min(freq['T'], min(freq['G'], freq['C']));
    printf("%d\n", ans);
    return 0;
}
