// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/magical-word/
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(const int &n) {
    if (n == 2) return true;
    if (n == 1) return false;

    for (int i = 2; i < sqrt(n) + 1; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(int argc, const char** argv) {
    vector<int> p;

    for (int i = 65; i < 91; i++) {
        if (isPrime(i)) p.push_back(i);
    }

    for (int i = 97; i < 123; i++) {
        if (isPrime(i)) p.push_back(i);
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        while (n--) {
            char c;
            cin >> c;
            int d = static_cast<int>(c);
            int x = __INT_MAX__;
            int r;
            for(auto i : p) {
                if (abs(i - d) <= x) {
                    if (abs(i-d) == x && i > r) continue;
                    x = abs(i-d);
                    r = i;
                }
            }
            cout << static_cast<char>(r);
        }
        cout << endl;
    }
}

