#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char** argv) {
    int minS = 0, maxS = 0, minF = 0, maxF = 0;
    int NS = 0, NF = 0;
    if (argc < 7) {
        printf("Required parameters: [NFeet] [NShoe] [minFootSize] [maxFootSize] [minShoeSize] [maxShoeSize]\n");
        return 1;
    }
    sscanf(argv[1], "%d", &NF);
    sscanf(argv[2], "%d", &NS);
    sscanf(argv[3], "%d", &minF);
    sscanf(argv[4], "%d", &maxF);
    sscanf(argv[5], "%d", &minS);
    sscanf(argv[6], "%d", &maxS);
    
    if (NS < 1 || NS > 1000 || NF < 1 || NF > 1000 || minS <= 0 || maxS > 10000 || minS > maxS || minF <= 0 || maxF > 10000 || minF > maxF ) {
        printf("ERROR: Outside allowable limits\n");
        return 1;
    }
    
    srand(time(NULL));
    
    int i, j;
    printf("%d %d\n", NF, NS);
    for (i = 0; i < NF; i++) {
        printf("%d\n", abs(rand() * rand() * rand()) % (maxF - minF + 1) + minF);
    }
    for (i = 0; i < NS; i++) {
        printf("%d\n", abs(rand() * rand() * rand()) % (maxS - minS + 1) + minS);
    }
    return 0;
}

