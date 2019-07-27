#include <iostream>
#include <string>
#include <utility>

using namespace std;

int main(int argc, const char** argv) {
    int tests;
    cin >> tests;
    cin.ignore(32767, '\n');
    while (tests--) {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        string big, small;

        if (a.length() > b.length()) {
            big = move(a);
            small = move(b);
        } else {
            big = move(b);
            small = move(a);
        }

        for(auto &ch : big) {
            size_t r = small.find(ch);
            if (r != string::npos) {
                small[r] = '0';
                ch = '0';
            }
        }

        int count{0};

        for (auto &ch : big) {
            if (ch != '0') count++;
        }
        for (auto &ch : small) {
            if (ch != '0') count ++;
        }
        cout << count << '\n';
    }
}

