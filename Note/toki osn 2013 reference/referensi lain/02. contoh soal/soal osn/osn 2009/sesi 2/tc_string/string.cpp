#include <stdio.h>
#include <string.h>

char s[258];
int M[258][258];
int N;

int main() {
	scanf ("%s", s);
	
	while (N * N < strlen (s))
		N++;
	
	while (strlen (s) < N * N) {
		s[strlen(s) + 1] = 0;
		s[strlen (s)] = '.';
	}
	
	int idx = 0;
	for (int i = 0; i < N; i++) {
		if (i % 2) {
			for (int j = N - 1; j >= 0; j--)
				M[i][j] = s[idx++];
		} else {
			for (int j = 0; j < N; j++)
				M[i][j] = s[idx++];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf ("%c", M[i][j]);
		printf ("\n");
	}
	
	return 0;
}
