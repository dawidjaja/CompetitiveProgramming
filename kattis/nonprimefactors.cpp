#include <cstdio>
#include <utility>
typedef std::pair<int,int> ii;
#define MAXN 3000001
int sieve[MAXN];
ii cached[MAXN];

int main() {
    for(long long i=2;i<MAXN;i++) {
        if(sieve[i] == 0) {
            sieve[i] = i;
            for(long long j=i*i;j<MAXN;j+=i) {
                if(sieve[j] == 0) sieve[j] = i;
            }
        }
    }

    int q;
    scanf(" %d",&q);
    for(int i=0;i<q;i++) {
        int val;
        scanf(" %d",&val);
        if(cached[val] == ii(0,0)) {
            int fac = sieve[val];
            int cur = val/fac;
            
            int curFacCount = 1;
            int numPrimes = 1;
            int comb = 1;
            while(cur > 1) {
                //printf("sieve[%d] = %d\n", cur, sieve[cur]);
                if(sieve[cur] == fac) {
                    curFacCount++;
                } else {
                    numPrimes++;
                    comb *= curFacCount + 1;
                    //printf("%d^%d\n", fac, curFacCount);
                    curFacCount = 1;
                    fac = sieve[cur];
                }
                cur /= sieve[cur];
                //printf("cur %d\n", cur);
            }
            comb *= curFacCount + 1;
            //printf("%d^%d\n", fac, curFacCount);
            printf("%d\n", comb - numPrimes);
        }
    }
    return 0;
}

