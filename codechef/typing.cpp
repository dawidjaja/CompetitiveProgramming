#include <algorithm>
#include <cstdio>
#include <map>
#include <iostream>

using namespace std;

int tc, n, ans;
map <char, int> hand;
map <string, int> history;
char word[50];

int get(string word) {
    double res = 2;
    for (int i = 1; i < word.length(); i++) {
        if (hand[word[i]] != hand[word[i - 1]])
            res += 2;
        else 
            res += 4;
    }
    return res;
}

int main() {
    scanf("%d", &tc);
    hand['d'] = hand['f'] = 1;
    hand['j'] = hand['k'] = 2;
    while (tc--) {
        scanf("%d", &n);
        history.clear();
        ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%s", word);
            if (history.count(word)) {
                ans += history[word];
            } else {
                int tmp = get(word);
                ans += tmp;
                history[word] = tmp / 2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
