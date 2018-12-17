#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

string dict[100005];
int cnt, vis[100005];
vector <int> v[2][100005];
unordered_map <string, int> words;
set <int> deps;

void dfs(int cur, int ver) {
    if (ver == 0) {
        deps.insert(cur);
        //printf("insert %d\n", cur);
        for (int i = 0; i < v[0][cur].size(); i++) {
            dfs(v[0][cur][i], ver);
        }
    } else {
        //printf(" -- %d --\n", cur);
        vis[cur] = 1;
        for (int i = 0; i < v[1][cur].size(); i++) {
            if (deps.count(v[1][cur][i]) && vis[v[1][cur][i]] == 0)
                dfs(v[1][cur][i], ver);
        }
        cout << dict[cur] << endl;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        string par;
        char buf[256];
        cin >> par;

        //par = par.substr(0, par.size()-1);
        par.pop_back();
        //getchar();

        fgets(buf, 256, stdin);

        string children(buf);
        string delimiter = " ";

        /*
        cout << ".<" << children << ">." << endl;
        children = children.substr(0, par.size() - 1);
        */

        size_t pos = 0;
        string token;
        if (!words.count(par)) {
            dict[cnt] = par;
            words[par] = cnt++;
            //cout << "--" << i << "-- " << cnt << " " << par << endl;
        }
        int p = words[par];
        int num;
        if (children == "\n") continue;
        children.pop_back();
        //children = children.substr(1, children.size() - 2);
        //cout << ".<" << children << ">." << endl;
        bool first = true;
        while ((pos = children.find(delimiter)) != string::npos) {
            if (first) {
                first = false;
                continue;
            }
            token = children.substr(0, pos);
            //cout << "token > " << token << endl;
            if (!words.count(token)) {
                dict[cnt] = token;
                words[token] = cnt++;
                //cout << "---- " << cnt << " " << dict[cnt - 1] << endl;
            }
            num = words[token];
            v[0][num].push_back(p);
            v[1][p].push_back(num);
            //printf("add edge (%d) -> (%d) \n", p, num);
            children.erase(0, pos + delimiter.length());
        }
        //cout << "token > " << children << endl;
        if (!words.count(children)) {
            dict[cnt] = children;
            words[children] = cnt++;
            //cout << "---- " << cnt << " " << dict[cnt - 1] << endl;
        }
        num = words[children];
        v[0][num].push_back(p);
        v[1][p].push_back(num);
        //printf("add edge (%d) -> (%d) \n", p, num);
    }
    char changed[16];
    scanf("%s", changed);
    int start = words[changed];
    dfs(start, 0);
    for (auto it = deps.begin(); it != deps.end(); it++) {
        if (vis[*it] == 0) {
            dfs(*it, 1);
        }
    }
    return 0;
}
