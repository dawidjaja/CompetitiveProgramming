/**
 * Reference solution for "Balet"
 * author: Prima C
 * created: 14 July 2009
 *
 * This serves as a sample of a solution with the "intended algorithm" to solve
 * task "Balet" as of 14 July 2009. Any update to the task after the date may
 * invalidate this solution.
 *         
 * The output of this "reference solution" should always be cross-checked with
 * another "reference solution" created by another individual.
 */
 
#include <stdio.h>
#include <algorithm>

using namespace std;

#define MAX_F   (1000)
#define MAX_S   (1000)

int F, S;
int feet[MAX_F];
int shoes[MAX_S];

int main() {
    int i, j;
    
    scanf("%d %d", &F, &S);
    for (i = 0; i < F; i++) {
        scanf("%d", &feet[i]);
    }    
    for (i = 0; i < S; i++) {
        scanf("%d", &shoes[i]);
    }
    sort(feet, feet+F);
    sort(shoes, shoes+S);
    
    int res = 0;
    i = S-1, j = F-1;
    while (i >= 0 && j >= 0) {
        while (shoes[i] < feet[j] && j >= 0) {
            j--;
        }
        if (j < 0) break;
        if (shoes[i] == feet[j] || shoes[i] == feet[j] + 1) {
            res++;
            j--;
        }
        i--;
    }
    printf("%d\n", res);
    return 0;
}
