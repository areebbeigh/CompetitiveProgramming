#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, const char** argv) {
    unsigned int X{1000000007};
    int t;
    cin >> t;
    
    long long unsigned int p{1};
    
    while (t--) {
        int n;
        cin >> n;
        p *= n;
        p %= X;
    }

    cout << p << '\n';
}

