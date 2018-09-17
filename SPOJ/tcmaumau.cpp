#include <bits/stdc++.h>
using namespace std;

#define LL      long long
#define ULL     unsigned long long
#define pii     pair<int,int>
#define fi      first
#define se      second
#define mp      make_pair
#define vi      vector<int>
#define psb     push_back
#define ppb     pop_back
#define all(x)     (x).begin(),(x).end()
#define sz      size()
#define endln     printf("\n")
#define gc     getchar_unlocked
#define setmin(x)   memset((x), -1, sizeof((x)))
#define setnul(x)   memset((x), 0, sizeof((x)))
#ifndef getchar_unlocked
#define getchar_unlocked  getchar
#endif
const int inf = (1<<30);
const int mod = 1e9 + 7;

void gi( int &ret ) {
 ret = 0; char inp=gc(); int kl=1;
 while (inp<'0' || inp>'9') {if (inp=='-') kl=-1; inp=gc();}
 while ('0'<=inp && inp<='9') ret=(ret<<3)+(ret<<1)+(int)(inp-'0'), inp=gc();
 if (kl<1) ret=-ret;
}

bool tes[35];
vi all;
char val[] = {'Q', 'K', 'S', 'E', 'N', 'T', 'A', 'J'};
char suit[] = {'C', 'S', 'H', 'D'};

int main() {
 srand(time(NULL));
 int tc; tc = rand() % 50;
 printf ("%d\n", tc);
 while (tc--) {
  setnul(tes);
  int n = rand()%3;
  n += 2;
  printf ("\n%d ", n);
  int asd = 0;
  for (int i=0; i<=10000000; i++) asd++;
  for (int i=0; i<32; i++) {
   int no = rand()%32;
   while (tes[no]) no = rand()%32;
   tes[no] = 1;
   all.psb(no);
  }
  for (int i=0; i<32; i++) {
   int a = all[i]%4, b = all[i]/4;
   printf ("%c%c ", suit[a], val[b]);
  }
 }
 return 0;
}
