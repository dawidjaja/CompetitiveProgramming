/**
 * Reference solution for "Dansa"
 * author: Prima C
 * created: 14 July 2009
 *
 * This serves as a sample of a solution with the "intended algorithm" to solve
 * task "Dansa" as of 14 July 2009. Any update to the task after the date may
 * invalidate this solution.
 *         
 * The output of this "reference solution" should always be cross-checked with
 * another "reference solution" created by another individual.
 */

#include <stdio.h>
#include <string>

int main() {
    int minX = 0, maxX = 0, minY = 0, maxY = 0;
    int currX = 0, currY = 0;
    int N;
    int i, j;
    char buf[1024];
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%s %d", buf, &j);
        if (!strcmp(buf, "maju")) {
            currX += j;
            if (currX > maxX) maxX = currX;
        } else if (!strcmp(buf, "mundur")) {
            currX -= j;
            if (currX < minX) minX = currX;
        } else if (!strcmp(buf, "kanan")) {
            currY += j;
            if (currY > maxY) maxY = currY;
        } else if (!strcmp(buf, "kiri")) {
            currY -= j;
            if (currY < minY) minY = currY;
        }
    }
    i = maxX - minX;
    j = maxY - minY;
    if (i > j) printf("%d %d\n", i, j);
    else printf("%d %d\n", j, i);
    return 0;
}
