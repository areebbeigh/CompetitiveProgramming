// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=424
// #include <iostream>
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char c;
    string s;
    while (cin >> noskipws >> c) {
        if (c == ' ' || c == '\n') {
            for (int i = s.length() - 1; i >= 0; i--) {
                cout << s[i];
            }
            cout << c;
            s = "";
        } else {
            s.push_back(c);
        }
    }
    // in case input doesn't have a new line
    for (int i = s.length() - 1; i >= 0; i--) {
        cout << s[i];
    }
}

