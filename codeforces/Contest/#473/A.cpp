#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  if(n & 1) {
    printf("Ehab\n");
  } else {
    printf("Mahmoud\n");
  }
  return 0;
}