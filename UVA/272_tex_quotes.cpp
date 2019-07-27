// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=208

#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    bool open = true;
    while (getline(cin, s)) {
        for(char &c : s) {
            if (c == '"' && open) {
                cout << "``";
                open = false;
            }
            else if (c == '"' && !open) {
                cout << "''";
                open = true;
            }
            else cout << c;
        }
        cout << endl;
    }
}

