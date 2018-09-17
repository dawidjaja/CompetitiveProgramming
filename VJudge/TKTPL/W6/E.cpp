#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>

#define fs first
#define sc second
#define pii pair<long long,long long>

using namespace std;

pii list[100005];
long long t, n, trgt, tes;
vector <long long> ats, bwh;
vector <pii> ans;

long long cek (long long a, long long b, long long c) {
  long long ta, tb, tc, td;
  ta = list[b].fs - list[a].fs;
  tb = list[b].sc - list[a].sc;
  tc = list[c].fs - list[b].fs;
  td = list[c].sc - list[b].sc;
  return ta * td - tb * tc;
}

int main() {
  scanf("%lld", &t);
  while(t--){
    scanf("%lld", &n);
    trgt = n / 10;
    for(long long i = 1; i <= n; i++) {
      scanf("%lld%lld", &list[i].fs, &list[i].sc);
    }

    sort(list + 1, list + 1 + n);

    ats.clear();
    bwh.clear();
    ans.clear();

    for(long long i = 1; i <= n; i++) {
      while(ats.size() >= 2 && cek(ats[ats.size() - 2], ats[ats.size() - 1], i) >= 0) {
        ats.pop_back();
      }
      ats.push_back(i);
      while(bwh.size() >= 2 && cek(bwh[bwh.size() - 2], bwh[bwh.size() - 1], i) <= 0) {
        bwh.pop_back();
      }
      bwh.push_back(i);
    }
    
    long long pa = 1;
    long long pb = 1;
    long long dpn = list[1].fs;
    long long ctr = 0;

    // for(long long i = 0; i < ats.size(); i++) {
    //   printf("atas - %lld %lld - \n", list[ats[i]].fs, list[ats[i]].sc);
    // }

    // for(long long i = 0; i < bwh.size(); i++) {
    //   printf("bwh - %lld %lld - \n", list[bwh[i]].fs, list[bwh[i]].sc);
    // }

    while(ctr < trgt && pa < (long long)ats.size() && pb < (long long)bwh.size()) {
      if(list[ats[pa]].fs == list[ats[pa - 1]].fs) {
        pa++;
        continue;
      } 
      if(list[bwh[pb]].fs == list[bwh[pb - 1]].fs) {
        pb++;
        continue;
      }

      tes = 0;
      
      long long ptr = min(list[ats[pa]].fs, list[bwh[pb]].fs);

      double ma = 1.0 * (list[ats[pa]].sc - list[ats[pa - 1]].sc) / (list[ats[pa]].fs - list[ats[pa - 1]].fs);
      double mb = 1.0 * (list[bwh[pb]].sc - list[bwh[pb - 1]].sc) / (list[bwh[pb]].fs - list[bwh[pb - 1]].fs);
      for(long long i = ptr - 1; i > dpn; i--) {

        // printf("ke %lld %lld\n", pa, pb);

        double tya = list[ats[pa - 1]].sc + ma * (i - list[ats[pa - 1]].fs);
        double tyb = list[bwh[pb - 1]].sc + mb * (i - list[bwh[pb - 1]].fs);
        long long ya = floor(tya);
        long long yb = ceil(tyb);
        // printf("-bef- %lld %lld - %lf %lf - %lld %lld - %lf %lf--\n", i, dpn, ma, mb, ya, yb, tya, tyb);

        if(ya == tya) {
          ya--;
        }
        if(yb == tyb) {
          yb++;
        }

        // printf("-aft- %lld %lld - %lf %lf - %lld %lld - %lf %lf--\n", i, dpn, ma, mb, ya, yb, tya, tyb);

        if(ya < yb) {
          tes = 1;
        } else {
          for(long long j = yb; j <= ya; j++) {
            ans.push_back({i, j});
            ctr++;
            if(ctr >= trgt) {
              break;
            }
          }
        }
        
        if(ctr >= trgt || tes) {
          break;
        }
      }

      if(ctr >= trgt) {
        break;
      }
      if(list[ats[pa]].fs <= list[bwh[pb]].fs) {
        pa++;
      } else {
        pb++;
      }
      dpn = ptr - 1;
    }
    if(ctr < trgt) {
      printf("-1\n");
    } else {
      for(long long i = 0; i < trgt; i++) {
        printf("%lld %lld\n", ans[i].fs, ans[i].sc);
      }
    }
    continue;
  }
  return 0;
}