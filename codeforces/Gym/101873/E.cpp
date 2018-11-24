#include <cstdio>
#include <cmath>
#include <utility>
#include <limits>
typedef long double ld;
#define MAXN 800
#define MAXM 4000
#define TOLERANCE 0
ld dist[MAXN][MAXN];
int adjlen[MAXN];


int main() {
    int n,m;
    scanf(" %d %d",&n,&m);
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            dist[i][j] = 10000000;
        }
        dist[i][i] = 0;
    }
    for(int i=0;i<m;i++) {
        int a,b;
        ld c;
        scanf(" %d %d %llf",&a,&b,&c);
        dist[a-1][b-1] = -log(c);
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            for(int k=0;k<n;k++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(dist[i][i] < TOLERANCE) {
            puts("inadmissible");
            return 0;
        }
    }
    puts("admissible");
    return 0;
}
