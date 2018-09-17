#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

deque <int> q;
int sim, aktif, val[20], list[10][15][15], num, kartu[10], t, org, turn;
char dummy, suit, tt;

inline void tulis(int x) {
	q.push_back(x);
	int a, b;
	a = x%4;
	b = x/4;
	sim = a;
	printf(" ");
	if(a == 0) {
		printf("D");
	} else if(a == 1) {
		printf("H");
	} else if(a == 2) {
		printf("S");
	} else if(a == 3) {
		printf("C");
	}
	if(b == 0) {
		printf("Q");
	} else if(b == 1) {
		printf("K");
	} else if(b == 2) {
		printf("S");
	} else if(b == 3) {
		printf("E");
	} else if(b == 4) {
		printf("N");
	} else if(b == 5) {
		printf("T");
	} else if(b == 6) {
		printf("A");
	} else if(b == 7) {
		printf("J");
	}
}

inline void tulispertama(int x) {
	q.push_back(x);
	int a, b;
	a = x%4;
	b = x/4;
//	printf("--");
	if(a == 0) {
		sim = 0;
		printf("D");
	} else if(a == 1) {
		sim = 1;
		printf("H");
	} else if(a == 2) {
		sim = 2;
		printf("S");
	} else if(a == 3) {
		sim = 3;
		printf("C");
	}
	if(b == 0) {
		printf("Q");
	} else if(b == 1) {
		printf("K");
	} else if(b == 2) {
		aktif += 2;
		printf("S");
	} else if(b == 3) {
		aktif = 1;
		printf("E");
	} else if(b == 4) {
		printf("N");
	} else if(b == 5) {
		printf("T");
	} else if(b == 6) {
		printf("A");
	} else if(b == 7) {
		sim = 5;
		printf("J");
	}
//	printf("--");
}

inline int bikinangka(char suit, char num) {
	int temp = 4;
	if(num == 'Q') {
		temp *= 0;
	} else if(num == 'K') {
		temp *= 1;
	} else if(num == 'S') {
		temp *= 2;
	} else if(num == 'E') {
		temp *= 3;
	} else if(num == 'N') {
		temp *= 4;
	} else if(num == 'T') {
		temp *= 5;
	} else if(num == 'A') {
		temp *= 6;
	} else if(num == 'J') {
		temp *= 7;
	}
	if(suit == 'H') {
		temp += 1;
	} else if(suit == 'S') {
		temp += 2;
	} else if(suit == 'C') {
		temp += 3;
	}
//	printf("%c%c --> %d %d\n", suit, num, temp/4, temp%4);
	return temp;
}

inline int ada7(int org) {
	for(int i = 3; i >= 0; i--) {
		if(list[org][2][i]) {
			return i;
		}
	}
	return -1;
}

inline int cck(int org, int simbol, int num) {
	if(simbol == 5) {
		for(int i = 7*4-1; i >= 0; i--) {
			if(list[org][i/4][i%4]) {
				return i;
			}
		}
	}
	int ret = -1;
	if(num != 7) {
		for(int i = 3; i >= 0; i--) {
			if(list[org][num][i]) {
				ret = num*4+i;
				break;
			}
		}
	}
	for(int i = 6; i >= 0; i--) {
		if(list[org][i][simbol]) {
			ret = max(ret, i*4+simbol);
			break;
		}
	}
	return ret;
}

inline int getJ(int org) {
	for(int i = 3; i >= 0; i--) {
		if(list[org][7][i]) {
			return i;
		}
	}
	return -1;
}

inline int ambil(int org) {
	int temp = q.front();
	list[org][q.front()/4][q.front()%4] = 1;
	kartu[org]++;
	q.pop_front();
	return temp;
}

inline int lambang(int org) {
	int ret, temp, gede;
	temp = 0;
	ret = -1;
	for(int j = 0; j <= 3; j++) {
		gede = 0;
		for(int i = 0; i <= 6; i++) {
			if(list[org][i][j] == 1) {
				gede++;
			}
		}
		if(gede >= temp) {
			temp = gede;
			ret = j;
		}
	}
	return ret;
}

inline void taro(int org, int x) {
	list[org][x/4][x%4] = 0;
	kartu[org]--;
//	printf("%d\n", x);
	tulis(x);
	if(x/4 == 2) {
		aktif += 2;
	}
	if(x/4 == 3) {
		aktif = 1;
	}
	if(x/4 == 7) {
		sim = lambang(org);
	}
	return;
}

inline int itung(int org) {
	int ret = 0;
	for(int i = 0; i < 4*8; i++) {
		if(list[org][i/4][i%4]) {
			ret += val[i/4];
		}
	}
	return ret;
}

inline void jawab() {
	printf("\nScore:");
	int mul = 1;
	if(q.back()/4 == 7) {
		mul = 2;
	}
	for(int i = 0; i < org; i++) {
		printf(" %d", itung(i)*mul);
	}
	printf("\n");
}

inline void reset() {
	while(q.size()) {
		q.pop_back();
	}
	for(int i = 0; i < org; i++) {
		for(int j = 0; j <= 8; j++) {
			for(int k = 0; k <= 5; k++) {
				list[i][j][k] = 0;
			}
		}
		kartu[i] = 0;
	}
	aktif = 0;
}

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &org);
		reset();
		for(int i = 1; i <= 32; i++){
			scanf("%c%c%c", &dummy, &suit, &tt);
			q.push_back(bikinangka(suit, tt));
		}
		for(int i = 1; i <= 9-org; i++) {
			for(int j = 0; j < org; j++) {
				int card = q.front();
				q.pop_front(); 
//				printf("%d -> %d %d\n",j, card/4, card%4);
				list[j][card/4][card%4] = 1;
				kartu[j]++;
			}
		}
		turn = 0;
		aktif = 0;
		sim = 5;
		tulispertama(q.front());
		q.pop_front();
		
		val[0] = 3;
		val[1] = 4;
		val[2] = 7;
		val[3] = 8;
		val[4] = 9;
		val[5] = 10;
		val[6] = 11;
		val[7] = 20;
		
//		0 Q
//		1 K
//		2 S
//		3 E
//		4 N
//		5 T
//		6 A
//		7 J
		
		while(true) {
			int atas = q.back();
			int card, n;
			n = atas/4;
//			printf("-- %d %d %d %d --\n", turn, n, sim, aktif);
			if(n == 2 && aktif) {
				// plus 2
//				printf("tujuh");
				int temp = ada7(turn);
				if(temp == -1) {
					//gada tujuh
					while(aktif--) {
						ambil(turn);
					}
					aktif = 0;
				} else {
					//ada tujuh
					taro(turn, 8+temp);
//					printf("aktif --> %d\n", aktif);
				}
			} else if(n == 3 && aktif) {
				//skip
				aktif = 0;
			} else if(n == 7) {
				//jack
				int temp = cck(turn, sim, n);
				if(temp == -1) {
					int porer = ambil(turn);
					if(porer%4 == sim && porer/4 <= 6) {
						taro(turn, porer);
					}
				} else {
					taro(turn, temp);
				}
			} else {
				int temp = cck(turn, sim, n);
				if(kartu[(turn+1)%org] == 1) {
					//kalo tgl 1, kluar jack
					int porer = getJ(turn);
					if(porer == -1) {
						//gapunya jack
						if(temp == -1) {
							//gapunya kartu
							int rerer = ambil(turn);
							if((rerer/4 == n || rerer%4 == sim) || rerer/4 == 7) {
								taro(turn, rerer);
							}
						} else {
							taro(turn, temp);
						}
					} else {
						//punya jack
						taro(turn, 28+porer);
					}
				} else if(temp == -1) {
					//biasa gaada kartu
					int porer = getJ(turn);
					if(porer == -1) {
						int porerer = ambil(turn);
						if((porerer/4 == n || porerer%4 == sim) || porerer/4 == 7) {
							taro(turn, porerer);
						}
					} else {
						taro(turn, 28+porer);
					}
				} else {
//					biasa ada kartu
					taro(turn, temp);
				}
			}
			if(kartu[turn] == 0) {
				jawab();
				break;
			}
			turn++;
			turn %= org;
		}
	}
	return 0;
}
