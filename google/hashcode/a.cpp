#include <bits/stdc++.h>

using namespace std;

int vis[100005], S[100005], B, L, D, totalSignup;

bool reverseCmp(int a, int b) {
    return S[a] > S[b];
}

struct Library {
    int N, T, M, id;
    vector<int> books;
    vector<int> pickBooks;
    int in;

    Library(int N, int T, int M, vector<int> &books, int id) {
        this->N = N;
        this->T = T;
        this->M = M;
        this->books = books;
        this->id = id;
        sort(this->books.begin(), this->books.end(), reverseCmp);
        this->pickBooks.assign(N, 0);
        this->in = 0;
    }

    /*
    int mark(vector<int> &vis, int get) {
        in = get;
        int ttl = 0;
        for (int i = 0; i < books; i++) {
            if (vis[books[i]] == 1 - get) {
                vis[books[i]] = get;
                //pickBooks[i] = get;
                ttl += S[books[i]];
            }
        }
        return ttl;
    }
    */

    int getBooks(int remD, int day) {
        int maxBooks = remD * M;
        int ttlScore = 0;
        for (int i = 0; i < N; i++) {
            if (vis[books[i]] != day) {
                vis[books[i]] = day;
                ttlScore += S[books[i]];
                pickBooks[i] = 1;
                if (--maxBooks == 0) {
                    break;
                }
            }
        }
        return ttlScore;
    }

    int getNBooks() {
        int nBooks = 0;
        for (int i = 0; i < N; i++) {
            if (pickBooks[i] == 1) {
                nBooks++;
            }
        }
        return nBooks;
    }

    void print() {
        int nBooks = getNBooks();
        int ctr = 0;
        if (nBooks == 0) return;
        printf("%d %d\n", id, nBooks);
        for (int i = 0; i < N; i++) {
            if (pickBooks[i]) {
                if (ctr++ == nBooks - 1) {
                    printf("%d\n", books[i]);
                } else {
                    printf("%d ", books[i]);
                }
            }
        }
    }

};

vector<Library> ans, libs, finAns;

bool initInsert(Library curLib) {
    if (totalSignup + curLib.T < D) {
        ans.push_back(curLib);
        totalSignup += curLib.T;
        /*
        totalScore += curLib.mark(vis, 1);
        */

        return true;
    }
    return false;
}

int getScore(int day) {
    int remD = D - totalSignup;

    int ttl = 0;
    for (int i = ans.size() - 1; i >= 0; i--) {
        ttl += ans[i].getBooks(remD, day);
        remD -= ans[i].T;
    } 
    return ttl;

}

int main() {
    srand(time(NULL));
    scanf("%d%d%d", &B, &L, &D);
    for (int i = 0; i < B; i++) {
        scanf("%d", &S[i]);
    }

    for (int i = 0; i < L; i++) {
        int TN, TT, TM;
        scanf("%d%d%d", &TN, &TT, &TM);

        vector<int> Tbooks;
        for (int j = 0; j < TN; j++) {
            int x;
            scanf("%d", &x);
            Tbooks.push_back(x);
        }
        libs.push_back(Library(TN, TT, TM, Tbooks, i));
    }


    int ctr = 50000;
    int curScore = 0;
    while(ctr--) {
        random_shuffle(libs.begin(), libs.end());

        int ptr = 0;
        while (ptr < libs.size()) {
            if (!initInsert(libs[ptr++])) {
                break;
            }
        }
        //printf("-- otto %d\n", totalSignup);

        int N = ans.size();
        for (int i = 0; i < B; i++) {
            vis[i] = -1;
        }

        int tmp = getScore(0);
        if (tmp > curScore) {
            curScore = tmp;
            finAns = ans;
        }

        int reps = 5000 / N;
        for (int _ = 1; _ < reps; _++) {
            random_shuffle(ans.begin(), ans.end());
            int tmp = getScore(_);
            if (tmp > curScore) {
                curScore = tmp;
                finAns = ans;
            }
        }
    }

    ans = finAns;
    for (int i = 0; i < B; i++) {
        vis[i] = -1;
    }
    assert(curScore == getScore(0));
    printf("-- %d --\n", curScore);
    int x = 0;
    for (int i = 0; i < finAns.size(); i++) {
        if (finAns[i].getNBooks()) {
            x++;
        }
    }
    printf("%d\n", x);

    for (int i = 0; i < finAns.size(); i++) {
        finAns[i].print();
    }

    return 0;
}
