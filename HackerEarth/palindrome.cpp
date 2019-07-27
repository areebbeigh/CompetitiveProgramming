#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char** argv) {
    string s;
    getline(cin, s);
    for (int i = 0, j = s.length() - 1; i < s.length() / 2; i++, j--)   {
        if (s[i] != s[j]) {
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    cout << "YES" << '\n';
}

