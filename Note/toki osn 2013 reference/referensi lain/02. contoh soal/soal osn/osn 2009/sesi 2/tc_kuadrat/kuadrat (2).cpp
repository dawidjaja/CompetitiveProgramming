#include<cstdio>

long long n;

int main(){
  scanf("%lld",&n);
  if (n == 1) {printf("0\n"); return 0;}
  for (int i = 1; ; i++){
      long long temp = (long long) i * (long long) i;
      if (temp == n) {printf("%lld\n",(long long)i);return 0;}
      else if (temp > n) {printf("0\n");return 0;}
  }  
} 
