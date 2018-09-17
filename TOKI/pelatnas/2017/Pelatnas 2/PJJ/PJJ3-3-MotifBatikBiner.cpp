#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>

#define fs first
#define sc second
#define mp make_pair
#define INF 1e6

using namespace std;

int n,dp[1000005], k, list[100005], ans, sblm;
priority_queue <pair<int,int> > pq;
char c;

int main () {
	scanf("%d%d", &n, &k);
	scanf("%c",&c);
	for(int i = 0; i < n; i++) {
		scanf("%c", &list[i]);
		list[i] -= '0';
	}
	list[n] = 1 - list[n-1];
	dp[n] = 0;
	sblm = n;
	
	for(int i = n-1; i >= 0; i--) {
		if(list[i] == list[i+1]) {
			for(int j = i+2; j <= min(sblm, i+k); j++) {
				pq.push(mp(-dp[j], j));
			}
			sblm = i+1;
		}
		while(pq.size()) {
			if(pq.top().sc > i+k) {
				pq.pop();
			} else {
				break;
			}
		}
		dp[i] = dp[i+1]+1;
		if(pq.size()) {
			dp[i] = min(dp[i], 1-pq.top().fs);
		}
	}
//	
//	for(int i = 0; i < n; i++) {
//		printf("%d ", dp[i]);
//	}
//	printf("\n");
	
	printf("%d\n",dp[0]-1);
	return 0;
}
