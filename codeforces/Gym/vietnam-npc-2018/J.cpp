#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char s[100005];
int n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", &s);
        int len = strlen(s);
        if (s[0] != s[len - 1]) {
            if (len % 2 == 0) {
                printf("Bash\n");
            } else {
                printf("Chikapu\n");
            }
        } else {
            if (len % 2 == 0) {
                printf("Chikapu\n");
            } else {
                printf("Bash\n");
            }
        }
    }
    return 0;
}
