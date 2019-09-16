// #include <iostream>
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;

    for (int i = 2; i < (int)sqrt(n) + 1; i++) {
        if (n % i == 0) return false;
    }

    return true;
}

vector<int> rotations(int n) {
    vector<int> res;
    string s = to_string(n);
    string rotation = *(s.end() - 1) + s.substr(0, s.size() - 1);
    while (rotation != s) {
        int x;
        stringstream ss;
        ss << rotation;
        ss >> x;
        res.push_back(x);
        ss.clear();
        rotation = *(rotation.end() - 1) + rotation.substr(0, rotation.size() - 1);
    }

    return res;
}

bool isCircular(int n, unordered_set<int> &primes) {
    for(auto p : rotations(n)) {
        if (primes.find(p) == primes.end()) return false;
    }
    // cout << n << endl;
    return true;
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_set<int> primes;
    for (int i = 2; i < 1000000; i++) {
        if (isPrime(i)) primes.insert(i);
    }

    int count = 0;
    for(auto p : primes) {
        if (isCircular(p, primes)) count++;
    }

    cout << count << endl;
}

