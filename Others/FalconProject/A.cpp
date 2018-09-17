#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int n;
vector <int> v;

int main() {
	scanf("%d", &n);
	if(n == 0) {
		printf("N\n");
		return 0;
	}
	while(n > 0) {
		v.push_back(n%6);
		n/=6;
	}
	for(int i = v.size() - 1; i >= 0; i--) {
		if(v[i] == 0) {
			printf("N");
		} else if(v[i] == 1) {
			printf("S");
		} else if(v[i] == 2) {
			printf("D");
		} else if(v[i] == 3) {
			printf("T");
		} else if(v[i] == 4) {
			printf("E");
		} else if(v[i] == 5) {
			printf("L");
		}
	}
	printf("\n");
	return 0;
}
