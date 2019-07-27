// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=882
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

ull factorial(ull n) {
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

void getPerm(string &s, ull n, string &out) {
    // Nth -> Permutation
    // for X:
    // sort given string
    // select char at index N / (L-1)!
    // index in subseq of permutations starting with X
    // I = N % (L-1)!
    // now we compute all permutations of N-1 ... but that's TLE
    // Ith -> Permutation
    // recursive case.
    sort(s.begin(), s.end());
    if (s.size() == 1) {
        out.push_back(s[0]);
        return;
    }

    ull x = n/factorial(s.size() - 1); // character that'll be left out
    char a = s[x];
    out.push_back(a);
    ull i = n % factorial(s.size() - 1);
    s.erase(s.begin() + x);
    // cout << "leaving out " << a << " size: " << s.size() << " next index: " << i << endl;
    return getPerm(s, i, out);
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string s;
        ull n;
        string o;
        cin >> s;
        cin >> n;
        getPerm(s, n, o);
        cout << o << endl;
    }
}

