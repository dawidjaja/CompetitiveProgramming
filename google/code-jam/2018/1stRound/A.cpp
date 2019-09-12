#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int ps[105][105], tt, r, c, tmph, bagi, cek, h, v, chip, trgt, list[105][105];
vector <int> vv, vh, tmpv;

int itung(int y1, int x1, int y2, int x2) {
  return ps[y2][x2] - ps[y1 - 1][x2] - ps[y2][x1 - 1] + ps[y1 - 1][x1 - 1];
}

int main() {
  scanf("%d", &tt);
  for(int tc = 1; tc <= tt; tc++) {
    scanf("%d%d%d%d", &r, &c, &h, &v);
    for(int i = 0; i <= r; i++) {
      for(int j = 0; j <= c; j++) {
        ps[i][j] = 0;
      }
    }
    chip = 0;
    for(int i = 1; i <= r; i++) {
      getchar();
      for(int j = 1; j <= c; j++) {
        list[i][j] = ((getchar() == '.') ? 0 : 1);
        if(list[i][j]) {
          chip++;
        }
        ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + list[i][j];
      }
    }
    // for(int i = 1; i <= r; i++) {
    //   for(int j = 1; j <= c; j++) {
    //     printf("%d ", ps[i][j]);
    //   }
    //   printf("\n");
    // }
    // printf(">>>>>>>\n\n %d\n\n <<<<<<\n\n", tc);
    if(chip == 0) {
      printf("Case #%d: POSSIBLE\n", tc);
      continue;
    }
    vh.clear();
    vv.clear();
    vh.push_back(0);
    vv.push_back(0);
    tmph = 0;
    bagi = chip / (h + 1);
    trgt = bagi / (v + 1);
    cek = 0;
    // printf("---- %d %d -----\n", bagi, trgt);
    if(chip % ((h + 1) * (v + 1)) == 0) {
      for(int i = 1; i <= r; i++) {
        tmph = itung(vh.back() + 1, 1, i, c);
        // printf("-- %d %d %d--\n", i, tmph, vh.back());
        if(tmph == bagi) {
          // printf("ini vh %d --", i);
          vh.push_back(i);
          tmph = 0;
        } else if(tmph > bagi) {
          cek = 1;
          // printf("aaa");
          printf("Case #%d: IMPOSSIBLE\n", tc);
          break;
        }
      }
      if(cek == 1) {
        continue;
      }
      tmpv.clear();
      int tvh = vh.size();
      for(int i = 0; i < tvh; i++) {
        tmpv.push_back(0);
        // printf("%d ", vh[i]);
      }
      int tvs = tmpv.size(); 
      for(int j = 1; j <= c; j++) {
        int tes = 0;
        int ada = 0;
        for(int i = 1; i < tvs; i++) {
          tmpv[i] = itung(vh[i - 1] + 1, vv.back() + 1, vh[i], j);
          // printf("-- %d %d %d-- \n", tmpv[i],  j, i);
          if(tmpv[i] == trgt) {
            ada++;
          }
          if(tmpv[i] > trgt) {
            tes = 1;
            break;
          }
        }
        // printf("\n");
        if(tes == 1) {
          cek = 1;
          // printf("bbb");
          printf("Case #%d: IMPOSSIBLE\n", tc);
          break;
        }
        if(ada == (h + 1)) {
          for(int i = 1; i < tvs; i++) {
            tmpv[i] = 0;
            vv.push_back(j);
          }
        } 
        // else if(ada != 0) {
        //   cek = 1;
        //   printf("ccc");
        //   printf("Case #%d: IMPOSSIBLE\n", tc);
        //   break;
        // }
      }
      if(cek == 0) {
        printf("Case #%d: POSSIBLE\n", tc);
      }
    } else {
      printf("Case #%d: IMPOSSIBLE\n", tc);
    }
  }
  return 0;
}