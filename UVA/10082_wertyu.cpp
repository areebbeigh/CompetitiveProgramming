// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1023
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string keyboard = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    string except = "QAZ`";
    string s;
    while (getline(cin, s)) {
        for(auto &c : s) {
            if (c == ' ') {
                cout << ' ';
                continue;
            }

            if (except.find(c) != string::npos) {
                cout << c;
                continue;
            }

            cout << keyboard[keyboard.find(c) - 1];
        }
        cout << endl;
    }
}

