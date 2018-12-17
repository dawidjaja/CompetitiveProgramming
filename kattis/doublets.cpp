#include <algorithm>
#include <cstdio>
#include <set>
#include <cstring>
#include <iostream>

using namespace std;

map <string, int> words;
char s[20];
char b[20];

int main() {
    while (true) {
        scanf("%s", s);
        char c = getchar();
        if (c == ' ') {
            scanf("%s", b);
            if (words.count(b)) {
                printf("ada\n");
            } else {
                printf("gaada\n");
            }
        } else {
            if (!words.count(s)) {
                words[s] = id++;

            }
        }
    }
}
