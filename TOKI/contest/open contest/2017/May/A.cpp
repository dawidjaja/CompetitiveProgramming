#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

char kata[105];
int temp, a, k, list[105];

int main() {
	scanf("%s", kata);
	temp = 0;
	for(int i = 0; i < strlen(kata); i++) {
		if(kata[i] == '_') {
			temp++;
		}
	}
	for(int i = 0; i < temp; i++) {
		list[i] = 0;
	}
	scanf("%d", &k);
	k--;
	while(k--) {
		list[temp - 1]++;
		for(int i = temp - 1; i > 0; i--){ 
			if(list[i] >= 26) {
				list[i] = 0;
				list[i-1]++;
			}
		}
	}
	a = 0;
	for(int i = 0; i < strlen(kata); i++) {
		if(kata[i] == '_') {
			printf("%c", list[a++] + 'a');
		} else {
			printf("%c", kata[i]);
		}
	}
	printf("\n");
	return 0;
}
