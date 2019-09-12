#include <bits/stdc++.h>

using namespace std;

int gcdExtended(int a, int b, int *x, int *y) 
{ 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 

    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 

    *x = y1 - (b/a) * x1; 
    *y = x1; 

    return gcd; 
} 

void modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "IMPOSSIBLE" << endl; 
    else
    { 
        int res = (x%m + m) % m; 
        cout << res << endl; 
    } 
} 

int main() 
{ 
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int a, m;
        scanf("%d%d", &m, &a);
        if (a == 1) {
            printf("%d\n", m + 1);
        } else if (m == 1) {
            printf("1\n");
        } else {
            modInverse(a, m); 
        }
    }
    return 0; 
} 
