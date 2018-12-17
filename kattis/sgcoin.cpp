#include <cstdio>
#include <cstring>
#define BASE 1000000007
#define TARGET 930000000
typedef long long ll;

ll hash(ll prev, char* str, int len) {
    ll v = prev;
    for(int i=0;i<len;i++) {
        v = (v * 31 + str[i]) % BASE;
    }
    return v;
}

char blah[] = "charlie-pays-to-eve-9-sg-coins";
int target = 930000000;
char blah2[] = "icpc-sg-2018-at-nus";
int target2 = 730000000;

int main() {
    ll val;
    scanf("%lld",&val);
    int len = strlen(blah);
    ll first = hash(val, blah, len);
    ll tok1 = (target - first * 7) % BASE;
    if(tok1 < 0) tok1 += BASE;
    //printf("hash1 %lld\n", (first * 7 + tok1) % BASE);

    int len2 = strlen(blah2);
    ll second = hash(target, blah2, len2);
    ll tok2 = (target2 - second * 7) % BASE;
    if(tok2 < 0) tok2 += BASE;
    //printf("hash2 %lld\n", (second * 7 + tok2) % BASE);
    
    printf("%s %lld\n%s %lld\n", blah, tok1, blah2, tok2);    
}

