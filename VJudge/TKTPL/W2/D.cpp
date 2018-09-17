#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>

#define fs first
#define sc second
#define pii pair<long long,long long>

using namespace std;

set <long long> isi;
long long ctr, n, x;
vector <long long> list;

inline long long baca() {
  long long temp = 0;
  char c;
  c = getchar_unlocked();
  while(c < '0' || c > '9') {
    c = getchar_unlocked();
  }
  while(c >= '0' && c <= '9') {
    temp = ((temp << 3) + (temp << 1));
    temp += c - '0';
    c = getchar_unlocked();
  }
  return temp;
}

int main() {
  n = baca();
	for(long long i = 1; i <= n; i++) {
		x = baca();
    list.push_back(x);
	}
  list.erase(unique(list.begin(), list.end()), list.end());
  n = list.size();
  set <long long> a[2];
  long long tes = 0;
	for(long long i = 0; i < n; i++) {
		for(auto it = a[tes].begin(); it != a[tes].end(); it++) {
      long long tmp = __gcd((long long)*it, list[i]);
      a[tes ^ 1].insert(tmp);
      isi.insert(tmp);

    }
    a[tes ^ 1].insert(list[i]);
    isi.insert(list[i]);
    a[tes].clear();
    tes ^= 1;
	}
  printf("%lld\n", (long long)isi.size());
	return 0;
}