#include <algorithm>
#include <cstdio>

using namespace std;

int a, b;

bool f(int a, int b) {
    int x = max(a, b);
    int y = min(a, b);
    if (x % y == 0)
        return (1);
    if (x / y == 1)
        return (f(x % y, y) ^ 1);
    else
        return ((f(x % y, y) & f(x % y + y, y)) ^ 1);
}

int main()
{
    while (scanf("%d%d", &a, &b) && (a != 0 && b != 0)) {
        if (f(a, b))
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}