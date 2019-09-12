#include<bits/stdc++.h> 
using namespace std; 

long long inv(long long a, long long m, long long mod) 
{ 
    long long m0 = m, t, q; 
    long long x0 = 0, x1 = 1; 

    if (m == 1) 
        return 0; 

    while (a > 1) 
    { 
        q = a / m; 
        t = m; 
        m = a % m;
        a = t; 
        t = x0; 
        x0 = x1 - q * x0; 
        x1 = t; 
    } 

    if (x1 < 0) 
        x1 += m0; 

    return x1; 
} 

long long findMinX(long long num[], long long rem[], long long k) 
{ 
    long long result = 0; 
    long long prod = num[0] * num[1];

    for (long long i = 0; i < k; i++) 
    { 
        long long pp = num[1 - i]; 
        result += ((rem[i] * inv(pp, num[i], prod)) % prod) * pp % prod; 
    } 

    return result % prod; 
} 
long long num[10]; 
long long rem[10]; 

int main(void) 
{ 
    long long tc;
    scanf("%lld", &tc);
    while (tc--) {
        long long a, b, n, m;
        scanf("%lld%lld%lld%lld", &a, &n, &b, &m);
        num[0] = n;
        num[1] = m;
        rem[0] = a;
        rem[1] = b;
        cout << findMinX(num, rem, 2) << ' ' << n * m << endl; 
    }
    return 0; 
} 

