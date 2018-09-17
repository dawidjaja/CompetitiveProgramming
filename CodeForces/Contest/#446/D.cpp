#include <algorithm>
#include <cstdio>

using namespace std;

int n, list[25], ttl, ps[25], ctr;

void shuffle(int a[], int n)
{
    for (int i=0; i < n; i++)
        swap(a[i + 1], a[rand()%n + 1]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &list[i]);
		ps[i] = ps[i - 1] + list[i];
	}
	sort(list + 1, list + n + 1);
	do {
		ttl = 0;
		ctr++;
		if(ctr >= 100000) {
			shuffle(list, n);
			for(int j = 1; j <= n; j++) {
				if(j == n) {
					printf("%d\n", list[n]);
					return 0;
				}
				printf("%d ", list[j]);

			}
			// printf("\n");
		}
		// for(int j = 1; j <= n; j++) {
		// 	printf("%d ", list[j]);
		// }
		for(int i = 1; i < n; i++) {
			ttl += list[i];
			if(ttl == ps[i]) {
				// printf("-- > %d\n", i);
				break;
			} else {
				if(i == n - 1) {
					for(int j = 1; j <= n; j++) {
						if(j == n) {
							printf("%d\n", list[n]);
							return 0;
						}
						printf("%d ", list[j]);
				// return 0;
					}
				}
			}
		}
	} while(next_permutation(list + 1, list + 1 + n));
	return 0;
}