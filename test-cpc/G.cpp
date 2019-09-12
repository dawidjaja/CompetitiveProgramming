#include <bits/stdc++.h>

using namespace std;

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[a[i]].fs++;
        gdeA = max(gdeA, a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        freq[b[i]].sc++;
        gdeB = max(gdeB, b[i]);
    }

    if (gdeB > gdeA) {
        for (int i = 0; i < n; i++) {
            swap(freq[i].fs, freq[i].sc);
        }
    }

    sort(freq + 1, freq + 100000);
    b = 2;
    cur = 0;
    hit = 0;
    for (int i = 1; i <= 100000; i++) {
        cur += freq[i].fs;
        int ctr = freq[i].fs;
        while (ctr > 0) {
            if (ctr >= freq[b].sc) {
                freq[b].sc = 0;
                ctr -= freq[b].sc;
                b++;
            } else {
                freq[b].sc -= ctr;
                ctr = 0;
            }
        }
    }
    
}
