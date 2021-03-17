#include <bits/stdc++.h>

using namespace std;

struct Chip {
    long long x, y, z;
};

struct Rec {
    long long x, y, z, u, v, w;
};

Chip chip[1005];
Rec rec[1005];
long long a, b, c, m;

bool inside(long long a, long long x, long long y, long long z) {
    if (rec[a].x <= x && x <= rec[a].u && 
        rec[a].y <= y && y <= rec[a].v && 
        rec[a].z <= z && z <= rec[a].w) return true;
    return false;
}

bool overlap(long long a, long long b) {
    if (rec[a].u < rec[b].x ||
        rec[b].u < rec[a].x ||
        rec[a].v < rec[b].y ||
        rec[b].v < rec[a].y ||
        rec[a].w < rec[b].z ||
        rec[b].w < rec[a].z) {
        return false;
    }

    return false;
}

int main() {
    while(scanf("%lld", &a) && a != -1) {
        scanf("%lld%lld%lld", &b, &c, &m);

        for (long long i = 0; i < m; i++) {
            scanf("%lld%lld%lld", &chip[i].x, &chip[i].y, &chip[i].z);
        }

        long long cek = 1;
        long long ttl = 0;

        for (long long i = 0; i < m; i++) {
            scanf("%lld%lld%lld%lld%lld%lld", 
                    &rec[i].x, &rec[i].y, &rec[i].z, 
                    &rec[i].u, &rec[i].v, &rec[i].w);

            ttl += (rec[i].u - rec[i].x + 1)
                    * (rec[i].v - rec[i].y + 1)
                    * (rec[i].w - rec[i].z + 1);

            if (rec[i].x > rec[i].u || 
                rec[i].y > rec[i].v || 
                rec[i].z > rec[i].w ||
                rec[i].u > a || 
                rec[i].v > b || 
                rec[i].w > c) {
                cek = 0;
            }
        }
        

        if (!cek || ttl != a * b * c) {
            printf("NO\n");
            //printf("masalah volume %lld %lld %lld - %lld  \n", a, b, c, ttl);
            continue;
        }

        for (long long i = 0; i < m; i++) {
            for (long long j = i + 1; j < m; j++) {
                if (overlap(i, j)) {
                    cek = 0;
                    break;
                }
            }
            if (!cek) {
                break;
            }
        }

        if (!cek) {
            printf("NO\n");
            //printf("salah overlap\n");
            continue;
        }

        for (long long i = 0; i < m; i++) {
            if (!inside(i, chip[i].x, chip[i].y, chip[i].z)) {
                cek = 0;
                break;
            }
        }

        if (cek) {
            printf("YES\n");
        } else {
            printf("NO\n");
            //printf("ada chip lebih dari 2\n");
        }

    }
    return 0;
}
