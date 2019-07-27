// https://www.hackerearth.com/practice/basic-programming/complexity-analysis/time-and-space-complexity/practice-problems/algorithm/vowel-game-f1a1047c/
// #include <iostream>
#include <bits/stdc++.h> 

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string vowels = "aeiou";
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), [](unsigned char c){ return tolower(c); });
        int l = s.length();
        vector<unsigned long long> v;
        vector<int> vc;
        v.reserve(s.length());
        unsigned long long c = 0;
        for (int i = 0; i < l; i++) {
            if (vowels.find(s[i]) != string::npos) {
                c += 1;
                vc.push_back(i);
            }
            v.push_back(c);
        }

        unsigned long long r = 0;

        for(auto vi : vc) {
            unsigned long long after = l - 1 - vi;
            unsigned long long before = vi;
            r += before * after + before + after + 1;
        }
        cout << r << endl;
    }
}

