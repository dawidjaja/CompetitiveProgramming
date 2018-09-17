#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

vector <int> rute, v[450];
queue <int> q;
int cap[450][450], n, X, Y, x, y, makan, minum, ans, sblm[450];

void jalan() {
	rute.clear();
	int temp = 422;
	rute.push_back(422);
	while(sblm[rute.back()] != -2) {
		rute.push_back(sblm[rute.back()]);
//		printf("%d\n", rute.back());
	}
	return;
}

inline bool SPFA() {
//	printf("asdf");
	while(q.size()) {
		q.pop();
	}
	rute.clear();
	for(int i = 0; i <= 422; i++) {
		sblm[i] = -1;
	}
	sblm[421] = -2;
//	vis[0] = 1;
	q.push(421);
	while(q.size()) {
//		printf("-- %d --\n", q.front());
		int temp;
		temp = q.front();
		q.pop();
		for(int i = 0; i < v[temp].size(); i++) {
			if(cap[temp][v[temp][i]] > 0 && sblm[v[temp][i]] == -1) { 
				sblm[v[temp][i]] = temp;
				if(v[temp][i] == 422) {
					jalan();
					break;
				}
				q.push(v[temp][i]);
			}
		}
		if(rute.size()) {
			break;
		}
	}
	if(rute.size()) {
		return true;
	} 
	return false;
}

inline void bikin(int a, int b) {
	v[a].push_back(b);
	v[b].push_back(a);
	cap[a][b] = 1;
	cap[b][a] = 0;
}

int main() {
	scanf("%d%d%d", &n, &X, &Y);
	for(int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		for(int j = 1; j <= x; j++) {
			scanf("%d", &makan);
			bikin(makan + 210, i);
		}
		for(int j = 1; j <= y; j++) {
			scanf("%d", &minum);
			bikin(i + 105, minum + 315);
		}
	}
	
	for(int i = 0; i <= n; i++) {
		bikin(i, i + 105);
	}
	
	for(int i = 0; i <= X; i++) {
		bikin(421, i + 210);
	}
	
	for(int i = 0; i <= Y; i++) {
		bikin(i + 315, 422);
	}
	
	ans = 0;
	
	while(SPFA()) {
//		for(int i = rute.size()-1; i >= 0; i--) {
//			printf("%d ", rute[i]);
//		}
//		printf("\n");
		rute.pop_back();
		int blkg = 421;
		while(rute.size()) {
			cap[blkg][rute.back()]--;
			cap[rute.back()][blkg]++;
			blkg = rute.back();
			rute.pop_back();
		}
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
