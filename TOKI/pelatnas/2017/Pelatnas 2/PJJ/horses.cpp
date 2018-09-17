#include "horses.h"
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

long long MOD = 1000000007;
long long INF = 1000000001;
int n, m, tipe, pos, val;
vector <int> kali, gede, bgs, x, y;

void bikin(int skrg, int l, int r) {
	if(l == r) {
		kali[skrg] = gede[skrg] = x[l];
		return;
	}
	int tgh;
	tgh = (l + r) / 2;
	bikin(skrg*2, l, tgh);
	bikin(skrg*2+1, tgh + 1, r);
	kali[skrg] = (1LL * kali[skrg*2] * kali[skrg*2+1]) % MOD;
	gede[skrg] = min((long long)INF, 1LL * gede[skrg*2] * gede[skrg*2+1]);
	return;
}

int itunggede(int skrg, int l, int r, int criL, int criR) {
//	printf("-- %d %d %d %d %d --\n", skrg, l, r, criL, criR);
	if(r < criL || l > criR) {
		return 1;
	}
	if(criL <= l && r <= criR) {
		return gede[skrg];
	}
	int mid;
	mid = (l + r) / 2;
	int ret;
	ret = min((long long)INF, 1LL * itunggede(skrg*2, l, mid, criL, criR) * itunggede(skrg*2+1, mid+1, r, criL, criR));
//	printf("-- %d %d %d %d %d --> %d --\n", skrg, l, r, criL, criR, ret);
	return ret;
}

int itungkali(int skrg, int l, int r, int criL, int criR) {
	if(r < criL || l > criR) {
		return 1;
	}
	if(criL <= l && r <= criR) {
		return kali[skrg];
	}
	int mid;
	mid = (l + r) / 2;
	return (1LL * itungkali(skrg*2, l, mid, criL, criR) * itungkali(skrg*2+1, mid+1, r, criL, criR)) % MOD;
}

void bikinst(int skrg, int l, int r) {
	if(l == r) {
		bgs[skrg] = l;
		return;
	}
	int mid = (l + r) / 2;
	bikinst(skrg*2, l, mid);
	bikinst(skrg*2+1, mid+1, r);
	int beda;
	beda = ceil(y[bgs[skrg*2]] / (double)y[bgs[skrg*2+1]]);
	if(itunggede(1, 0, n-1, bgs[skrg*2]+1, bgs[skrg*2+1]) >= beda) {
		bgs[skrg] = bgs[skrg*2+1];
	} else {
		bgs[skrg] = bgs[skrg*2];
	}
	return;
}

void upX(int skrg, int l, int r, int pos, int val) {
	if(l == r && l == pos) {
		kali[skrg] = gede[skrg] = x[pos] = val;
		return;
	}
	if(r < pos || pos < l) {
		return;
	}
	int mid = (l + r) / 2;
	upX(skrg*2, l, mid, pos, val);
	upX(skrg*2+1, mid + 1, r, pos, val);
	kali[skrg] = (1LL * kali[skrg*2] * kali[skrg*2+1]) % MOD;
	gede[skrg] = min((long long)INF, 1LL * gede[skrg*2] * gede[skrg*2+1]);
}

void update(int skrg, int l, int r, int pos, int val) {
	if(l == r && l == pos) {
		return;
	}
	if(r < pos || pos < l) {
		return;
	}
	int mid = (l + r) / 2;
	update(skrg*2, l, mid, pos, val);
	update(skrg*2+1, mid + 1, r, pos, val);
	int beda;
	beda = ceil(y[bgs[skrg*2]] / (double)y[bgs[skrg*2+1]]);
	if(itunggede(1, 0, n-1, bgs[skrg*2]+1, bgs[skrg*2+1]) >= beda) {
		bgs[skrg] = bgs[skrg*2+1];
	} else {
		bgs[skrg] = bgs[skrg*2];
	}
	return;
}

void updateXX(int skrg, int l, int r, int pos, int val) {
	upX(1, 0, n-1, pos, val);
	update(1, 0, n-1, pos, val);
	return;
}

int init(int N, int X[], int Y[]) {
	n = N;
	x = y = vector <int> (n);
	for(int i = 0; i < n; i++) {
		x[i] = X[i];
		y[i] = Y[i];
	}
	bgs = kali = gede = vector <int> (n*4);
	bikin(1, 0, n-1);
	bikinst(1, 0, n-1);
	long long ans;
	ans = (1LL * itungkali(1, 0, n-1, 0, bgs[1])*y[bgs[1]]) % MOD;
	return ans;
}

int updateX(int pos, int val) {	
	updateXX(1, 0, n-1, pos, val);
	long long ans;
	ans = (1LL * itungkali(1, 0, n-1, 0, bgs[1])*y[bgs[1]]) % MOD;
	return ans;
}

int updateY(int pos, int val) {
	y[pos] = val;
	update(1, 0, n-1, pos, val);
	long long ans;
	ans = (1LL * itungkali(1, 0, n-1, 0, bgs[1])*y[bgs[1]]) % MOD;
	return ans;
}
