#include <algorithm> 
#include <cstdio>
#include <queue>

using namespace std;

deque <int> dq;
int cek[5000100], grid[5000100], r, c, k, h, t, y[5000100], x[5000100], awal, akhir;

void dfs(int skrg) {
	// printf("-- %d\n", skrg);
	if(cek[skrg] == 2) {
		cek[skrg] = 0;
		dq.push_back(grid[skrg]);
		if(dq.size() >= 100) {
			return;
		}
		if(((skrg + 1) < r * c) && cek[skrg + 1] == 2) {
			dfs(skrg + 1);
		} else if(((skrg + c) < r * c) && cek[skrg + c] == 2) {
			dfs(skrg + c);
		} else if(((skrg - 1) >= 0) && cek[skrg - 1] == 2) {
			dfs(skrg - 1);
		} else if(((skrg - c) >= 0) && cek[skrg - c] == 2) {
			dfs(skrg - c);
		}
	}
	return;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &r, &c, &k, &h);
		for(int i = 1; i <= r; i++) {
			for(int j = 1; j <= c; j++) {
				int temp;
				temp = ((((i - 1) * c + j) * k + h) % (r * c)) + 1;
				y[temp] = i - 1;
				x[temp] = j - 1;
				grid[(i - 1) * c + j - 1] = temp;
			}
		}
		for(int i = 0; i <= r * c; i++) {
			cek[i] = 0;
			// printf("%lld --> %lld %ll\dn", i, y[i], x[i]);
		}
		awal = 0;
		akhir = 0;
		for(int l = 1; l <= r * c; l++) {
			if(cek[y[l] * c + x[l]] == 0) {
				// printf("%lld\n", l);
				cek[y[l] * c + x[l]] = 2;
				if(grid[0] == l) {
					awal = 1;
				}
				if(grid[r * c - 1] == l) {
					akhir = 1;
				}
				for(int i = y[l] - 1; i >= 0; i--) {
					for(int j = x[l] + 1; j < c; j++) {
						int skrg = i * c + j;
						// printf("---- %lld %lld %lld \n", i, j, i * c + j);
						if(cek[skrg] == 1) {
							break;
						}
						cek[skrg] = 1;
					}
				}
				for(int i = y[l] + 1; i < r; i++) {
					for(int j = x[l] - 1; j >= 0; j--) {
						int skrg = i * c + j;	
						// printf("---- %lld %lld %lld \n", i, j, i * c + j);
						if(cek[skrg] == 1) {
							break;
						}
						cek[skrg] = 1;
					}
				}
				if(akhir && awal) {
					break;
				}
				// for(int i = 0; i < r * c; i++) {
				// 	printf("%d ", cek[i]);
				// 	if(i % c == c-1) {
				// 		printf("\n");
				// 	}
				// }
			}
		}
		// for(int i = 0; i < r * c; i++) {
		// 	printf("%d ", cek[i]);
		// 	if(i % c == c-1) {
		// 		printf("\n");
		// 	}
		// }
		dq.clear();
		dfs(0);
		while(dq.size()) {
			printf("%07d\n", dq.front());
			dq.pop_front();
		}
		dfs(r * c - 1);
		while(dq.size()) {
			printf("%07d\n", dq.back());
			dq.pop_back();
		}
	}
	return 0;
}