#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int sblm[1005], flow[1005][1005], kj, so, si, r, c, a[10], b[10], ans;
vector <int> v[1005], path;
const int INF = INT_MAX;

bool can(int x, int y, int z) {
	if (x + a[z] >= 0 && x + a[z] < r &&
		y + b[z] >= 0 && y + b[z] < c) {
		return true;
	}
	return false;
}

bool SPFA() {
	queue <int> q;
	for (int i = 0; i <= si; i++) {
		sblm[i] = -2;
	}
	q.push(so);
	sblm[so] = -1;
	while (q.size()) {
		int cur = q.front();
		printf("%d %d\n", cur / r, cur % r);
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			printf("%d --> %d\n", cur, v[cur][i]);
			if (sblm[v[cur][i]] == -2 && flow[cur][v[cur][i]] > 0) {
				sblm[v[cur][i]] = cur;
				q.push(v[cur][i]);
			}
		}
	}
	if (sblm[si] == -2) {
		return false;
	}
	return true;
}

int main() {
	a[0] = b[1] = 1;
	a[2] = b[3] = -1;
	scanf("%d%d", &r, &c);
	so = 2 * r * c;
	si = 2 * r * c + 1;
	kj = 0;
	for (int i = 0; i < r; i++) {
		getchar();
		for (int j = 0; j < c; j++) {
			char c = getchar();
			int fsNode = i * r + j;
			int scNode = i * r + j + r * c;
			v[so].push_back(fsNode);
			v[scNode].push_back(si);
			// ini bisa dimasukin backedgenya kalo WA
			if (c == 'o') {
				flow[so][fsNode] = 1;
				flow[scNode][si] = 1;
				kj += 1;
			} else {
				flow[so][fsNode] = 2;
				flow[scNode][si] = 2;
				kj += 2;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			for (int k = 0; k < 4; k++) {
				if (can(i, j, k)) {
					int fsa = i * r + j;
					int sca = i * r + j + r * c;
					int fsb = (i + a[k]) * r + j + b[k];
					int scb = (i + a[k]) * r + j  + b[k] + r * c;
					v[fsa].push_back(scb);
					v[sca].push_back(fsb);
					v[fsb].push_back(sca);
					v[scb].push_back(fsa);
					flow[fsa][scb] = INF;
					flow[fsb][sca] = INF;
				}
			}
		}
	}
	while (SPFA()) {
		path.clear();
		int tmp = si;
		path.push_back(si);
		int bottleNeck = INF;
		while (sblm[tmp] >= 0) {
			bottleNeck = min(bottleNeck, flow[tmp][sblm[tmp]]);
			tmp = sblm[tmp];
			path.push_back(tmp);
		}
		for (int i = 0; i < path.size() / 2; i++) {
			swap(path[i], path[path.size() - 1 - i]);
		}
		for (int i = 0; i < path.size() - 1; i++) {
			printf("%d %d --> %d\n", path[i], path[i + 1], bottleNeck);
			flow[path[i]][path[i + 1]] -= bottleNeck;
			flow[path[i + 1]][path[i]] += bottleNeck;
		}
		ans += bottleNeck;
		printf("\n");
	}
	if (kj == ans) {
		printf("Y\n");
	} else {
		printf("N\n");
	}
	return 0;
}

