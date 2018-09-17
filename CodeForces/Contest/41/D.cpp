#include <algorithm>
#include <cstdio>

#define fs first
#define sc second
#define pii pair<long long,long long>

using namespace std;

pii list[100005];
long long n;

inline bool cek() {
  long long my = list[2].sc - list[1].sc;
  long long mx = list[2].fs - list[1].fs;
  long long a = -1;
  long long b = -1;
  long long ty, tx;
  long long salah = 0;
  for(long long i = 3; i <= n; i++) {
    long long yy = list[i].sc - list[1].sc;
    long long xx = list[i].fs - list[1].fs;
    if(xx * my == yy * mx) {
      continue;
    } else {
      if(a == -1) {
        a = i;
      } else if(b == -1) {
        b = i;
        ty = list[b].sc - list[a].sc;
        tx = list[b].fs - list[a].fs;
      } else {
        long long yyy = list[i].sc - list[a].sc;
        long long xxx = list[i].fs - list[a].fs;
        if(xxx * ty == yyy * tx) {
          continue;
        } else {
          salah = 1;
          break;
        }
      }
    }
  }
  if(salah == 0) {
    return true;
  }
  my = list[3].sc - list[1].sc;
  mx = list[3].fs - list[1].fs;
  a = 2;
  b = -1;
  salah = 0;
  for(long long i = 4; i <= n; i++) {
    long long yy = list[i].sc - list[1].sc;
    long long xx = list[i].fs - list[1].fs;
    if(xx * my == yy * mx) {
      continue;
    } else {
      if(a == -1) {
        a = i;
      } else if(b == -1) {
        b = i;
        ty = list[b].sc - list[a].sc;
        tx = list[b].fs - list[a].fs;
      } else {
        long long yyy = list[i].sc - list[a].sc;
        long long xxx = list[i].fs - list[a].fs;
        if(xxx * ty == yyy * tx) {
          continue;
        } else {
          salah = 1;
          break;
        }
      }
    }
  }

  if(salah == 0) {
    return true;
  }
  my = list[3].sc - list[2].sc;
  mx = list[3].fs - list[2].fs;
  a = 1;
  b = -1;
  salah = 0;
  for(long long i = 4; i <= n; i++) {
    long long yy = list[i].sc - list[2].sc;
    long long xx = list[i].fs - list[2].fs;
    if(xx * my == yy * mx) {
      continue;
    } else {
      if(a == -1) {
        a = i;
      } else if(b == -1) {
        b = i;
        ty = list[b].sc - list[a].sc;
        tx = list[b].fs - list[a].fs;
      } else {
        long long yyy = list[i].sc - list[a].sc;
        long long xxx = list[i].fs - list[a].fs;
        if(xxx * ty == yyy * tx) {
          continue;
        } else {
          salah = 1;
          break;
        }
      }
    }
  }

  if(salah == 0) {
    return true;
  }
  return false;
}

int main() {
  scanf("%lld", &n);
  if(n <= 4) {
    printf("YES\n");
    return 0;
  }
  for(long long i = 1; i <= n; i++) {
    scanf("%lld%lld", &list[i].fs, &list[i].sc);
  }
  if(cek()) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}