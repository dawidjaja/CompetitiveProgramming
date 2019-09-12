#include <algorithm>
#include <cstdio>

using namespace std;

void updateX(int idx, int l, int r, int x1, int x2, int y1, int y2, int id) {
    if (x1 <= l && r <= x2) {
        updateY(
    }
}

void update(int x1, int y1, int x2, int y2, int id) {
    updateX(1, 1, 5000, x1, x2, y1, y2, id);
}

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            id++;
            list[id] = {{x1, y1}, {x2, y2}};
            update(x1, y1, x2, y2, id);
        } else if (type == 2) {
            scanf("%d", &x);
            remove(list[x].fs.fs, list[x].fs.sc, list[x].sc.fs, list[x].sc.sc);
        } else if (type == 3) {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if (get(x1, y1) == get(x2, y2)) {
                printf("Y");
            } else  {
                printf("N");
            }
        }

    }
    return 0;
}
