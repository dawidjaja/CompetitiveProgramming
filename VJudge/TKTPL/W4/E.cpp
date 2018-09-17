//radix sort taken from TKTPL slide

#include <bits/stdc++.h>

#define MAX_N 100010 // second approach: O(n log n)

using namespace std;

char list[20];
string s;

char T[MAX_N]; // the input string, up to 100K characters
int n; // the length of input string
int RA[MAX_N], tempRA[MAX_N]; // rank array and temporary rank array
int SA[MAX_N], tempSA[MAX_N]; // suffix array and temporary suffix array
int c[MAX_N]; // for counting/radix sort
vector <string> v;
int ans, q;
void countingSort(int k) {
  int i, sum,
  maxi = max(300, n); // up to 255 ASCII chars or length of n
  memset(c, 0, sizeof c); // clear frequency table
  for (i = 0; i < n; i++) // count the frequency of each rank
    c[i + k < n ? RA[i + k] : 0]++;
  for (i = sum = 0; i < maxi; i++) {
    int t = c[i]; 
    c[i] = sum; 
    sum += t;
  }
  for (i = 0; i < n; i++) // shuffle the suffix array if necessary
    tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];
  for (i = 0; i < n; i++) // update the suffix array SA
    SA[i] = tempSA[i];
}

void constructSA() {
// this version can go up to 100000 characters
  int i, k, r;
  for (i = 0; i < n; i++) {
    RA[i] = T[i] - '.'; // initial rankings
  }
  for (i = 0; i < n; i++) {
    SA[i] = i; // initial SA: {0, 1, 2, ...,
  }
  for (k = 1; k < n; k <<= 1) {
  countingSort(k); // actually radix sort: sort based on the second item
  countingSort(0); // then (stable) sort based on the first item
  tempRA[SA[0]] = r = 0;
  for (i = 1; i < n; i++)
    tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k])?r :++r;
  for (i= 0;i< n; i++) // update the rank array RA
    RA[i] = tempRA[i];
  }
}


int main(){
  // printf("Enter a string T below, we will compute its Suffix Array:\n");
  cin >> T;
  n = (int)strlen(T);
  T[n++] = '.'; // important bug fix!
  constructSA(); // O(n log n)
  // printf("\nThe Suffix Array of string T = '%s' is shown below (O(n log n) version):\n", T);
  // printf("i\tSA[i]\tSuffix\n");
  for(int i = 0; i < n; i++) {
    // printf("%2d\t%2d\t%s\n", i, SA[i], T + SA[i]);
    v.push_back(T + SA[i]);
    
  } 

  // for(int i = 0; i < n; i++) {
    // printf("%2d\t%2d\t%s\n", i, SA[i], T + SA[i]);
  // }
  scanf("%d", &q);
  int vs = v.size();
  // for(int i = 0; i < vs; ++i) {
  //   cout << v[i] << endl;
  // }
  while(q--) {
    cin >> s;
    s += '.';
    ans = (upper_bound(v.begin(), v.end(), s) - v.begin());
    if(ans == vs) {
      printf("-1\n");
    } else {
      // cout << "--" << s << "--" << v[ans] << "--\n";
      int pjg = v[ans].size();
      int ps = s.size();
      for(int i = 0; i < pjg; ++i) {
        printf("%c", v[ans][i]);
        if(i > ps || v[ans][i] > s[i]) {
          break;
        }
      }
      printf("\n");
    }
  }
}