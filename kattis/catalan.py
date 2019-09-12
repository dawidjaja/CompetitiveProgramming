
dp = {}

def binomialCoefficient(n, k): 

    if (k > n - k): 
        k = n - k 

    res = 1

    for i in range(k): 
        res = res * (n - i) 
        res = res / (i + 1) 
    return res 

def catalan(n): 
    if (n in dp):
        return dp[n]
    c = binomialCoefficient(2*n, n) 
    dp[n] = c/(n + 1) 
    return dp[n]

tc = int(input())
for _ in range(tc):
    x = int(input())
    print(catalan(x))

