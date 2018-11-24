#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define pii pair<long long,long long>

using namespace std;

long long n, t, b[200005], vis[200005], sblm;
pii list[200005];

int main() {
    scanf("%lld%lld", &n, &t);
    for (long long i = 0; i < n; i++)
        scanf("%lld", &list[i].fs);
    for (long long i = 0; i < n; i++)
        scanf("%lld", &list[i].sc);
    sort(list, list + n);
    for (long long i = n - 1; i >= 0; i--) {
        if (vis[list[i].sc] == 1 && sblm != list[i].sc) {
            printf("No\n");
            return 0;
        }
        vis[list[i].sc] = 1;
        sblm = list[i].sc;
        printf("-- %lld %lld %lld\n--\n", sblm, list[i].fs, list[i].sc);
        if (sblm == list[i].sc) {
            b[list[i].sc] = b[list[i + 1].sc];
        }
        b[list[i].sc] = list[i].fs + 10;
    }
    printf("Yes\n");
    for (long long i = 1; i <= n; i++) {
        printf("%lld", b[i]);
        if (i == n)
            printf("\n");
        else 
            printf(" ");
    }
	return 0;
}
