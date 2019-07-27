#include <iostream>
#include <cmath>

using namespace std;


bool isPrime(const int &n) {
    if (n == 2) return true;
    if (n == 1) return false;

    for (int i = 2; i < sqrt(n) + 1; ++i) {
        // cout << "--" << i << '\n';
        if (n % i == 0) return false;
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) cout << i << ' ';
    }
}

