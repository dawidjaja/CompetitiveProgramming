#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int tc;
    string list[10];
    scanf("%d", &tc);
    list[7] = "8";
    list[6] = "0";
    list[5] = "2";
    list[4] = "4";
    list[3] = "7";
    list[2] = "1";
    while (tc--) {
        int n;
        scanf("%d", &n);
        int tmp = n;
        int bnyk;
        string gde, kcl;
        bnyk = n / 7;
        tmp = tmp % 7;
        if (tmp == 1) {
            kcl = "10";
            bnyk--;
        } else if (bnyk == 0) {
            kcl = list[tmp];
            if (6 == tmp) {
                kcl = "6";
            }
        } else {
            kcl = list[tmp];
            if (tmp == 3) {
                if (bnyk > 1) {
                    bnyk -= 2;
                    kcl = "200";
                } else {
                    bnyk--;
                    kcl = "22";
                }
            } else if (tmp == 4) {
                bnyk--;
                kcl = "20";
            } else if (tmp == 5) {
                bnyk--;
                kcl = "28";
            } else if (tmp == 6) {
                bnyk--;
                kcl = "68";
            }
        }
        for (int i = 0; i < bnyk; i++) {
            kcl += "8";
        }
        if (n & 1) {
            gde = "7";
            n -= 3;
        } else {
            gde = "";
        }
        while (n > 0) {
            n -= 2;
            gde += "1";
        }
        cout << kcl << " " << gde << endl;
    }
    return 0;
}
