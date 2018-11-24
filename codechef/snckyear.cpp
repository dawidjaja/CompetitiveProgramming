#include <algorithm>
#include <cstdio>

using namespace std;

int tc, year;

int main() {
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &year);
        if (year != 2010 &&
            year != 2015 &&
            year != 2016 &&
            year != 2017 &&
            year != 2019) {
            printf("NOT ");
        }
        printf("HOSTED\n");
    }
    return 0;
}
