// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=680
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    map<char, int> guide;
    guide.insert(pair<char, int>('B', 1));
    guide.insert(pair<char, int>('P', 1));
    guide.insert(pair<char, int>('F', 1));
    guide.insert(pair<char, int>('V', 1));
    guide.insert(pair<char, int>('C', 2));
    guide.insert(pair<char, int>('S', 2));
    guide.insert(pair<char, int>('K', 2));
    guide.insert(pair<char, int>('G', 2));
    guide.insert(pair<char, int>('J', 2));
    guide.insert(pair<char, int>('Q', 2));
    guide.insert(pair<char, int>('X', 2));
    guide.insert(pair<char, int>('Z', 2));
    guide.insert(pair<char, int>('D', 3));
    guide.insert(pair<char, int>('T', 3));
    guide.insert(pair<char, int>('L', 4));
    guide.insert(pair<char, int>('M', 5));
    guide.insert(pair<char, int>('N', 5));
    guide.insert(pair<char, int>('R', 6));
    string skip = "AEIOUYWH";

    cout << string(9, ' ') << "NAME" << string(21, ' ') << "SOUNDEX CODE" << endl;
    
    while (cin >> s) {
        cout << string(9, ' ') << s << string(35 - (9 + s.length()) - 1, ' ');
        string code;
        int pc;
        for (int i = 0; i < s.size(); i++) {
            if (code.size() >= 4) break;
            if (i == 0) code.push_back(s[i]);
            if (guide.find(s[i]) == guide.end()) {
                pc = 0;
                continue;
            }
            int x = guide.find(s[i])->second;
            if (x == pc) continue;
            stringstream ss;
            ss << x;
            char c;
            ss >> c;
            if (i != 0) code.push_back(c);
            pc = x;
        }
        cout << code;
        if (code.size() < 4) {
            cout << string(4 - code.size(), '0');
        }
        cout << endl;
    }
    cout << string(19, ' ') << "END OF OUTPUT" << endl;
}

