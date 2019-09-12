#include <algorithm>
#include <cstdio>

using namespace std;

int n;

int main() {
  scanf("%d", &n);
  if(n <= 5) {
    printf("-1\n");
  } else {
    printf("1 2\n");
    printf("2 3\n");
    printf("2 4\n");
    for(int i = 5; i <= n; i++) {
      printf("1 %d\n", i);
    }
  }
  for(int i = 2; i <= n; i++) {
    printf("%d %d\n", i - 1, i);
  }
  return 0;
}