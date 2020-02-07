// #include <iostream>
// http://codeforces.com/contest/1296/problem/C
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        map<int, map<int, int>> visited;
        visited[0][0] = -1;
        pair<int, int> pos;

        string res = "";
        int min_length = -1;

        string steps;
        int i = 0;
        cin >> steps;
        for(auto move : steps) {
            switch (move) {
                case 'L':
                    pos.first--;
                    break;
                case 'R':
                    pos.first++;
                    break;
                case 'U':
                    pos.second++;
                    break;
                case 'D':
                    pos.second--;
                    break;
            }
            int start = -2;
            auto x_map = visited.find(pos.first);
            if (x_map != visited.end()) {
                if (visited[pos.first].find(pos.second) != visited[pos.first].end()) {
                    // this node has already been visited. we hit a redundant subpath
                    start = visited[pos.first][pos.second];
                }
            }
            if (start != -2) {
                int path_length = i - start;
                if (min_length == -1 or path_length < min_length) {
                    if (start == -1) res = to_string(1) + " " + to_string(i + 1);
                    else res = to_string(start + 2) + " " + to_string(i + 1);
                    min_length = path_length;
                }
            }
            if (x_map != visited.end()) {
                x_map->second[pos.second] = i;
            } else {
                visited[pos.first] = map<int, int>{{pos.second, i}};
            }
            i++;
        }
        if (min_length != -1) cout << res;
        else cout << -1;
        cout << endl;
    }
}

