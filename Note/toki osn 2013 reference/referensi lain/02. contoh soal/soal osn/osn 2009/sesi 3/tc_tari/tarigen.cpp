#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char** argv) {
    if (argc < 3) {
        printf("Required parameters: [N] [size_limit]\n");
        return 1;
    }
    
    int N = 0, S = 0;
    sscanf(argv[1], "%d", &N);
    sscanf(argv[2], "%d", &S);
    
    if (N < 2 || N > 10000 || S <= 0) {
        printf("Outside allowable limits\n");
        return 1;
    }
    
    srand(time(NULL));
    int i, j;
    printf("%d\n", N);
    for (i = 0, j = 0; i < N; i++, j = 0) {
        switch (abs(rand() * rand() * S) % 4) {
        case 0: printf("maju"); break;
        case 1: printf("mundur"); break;
        case 2: printf("kiri"); break;
        case 3: printf("kanan"); break;
        }
        printf(" %d\n", abs(rand() * rand() * rand()) % (S - 1) + 1);;
    }
    return 0;
}
