// https://onlinejudge.org/index.php?Itemid=8&option=com_onlinejudge&page=show_problem&problem=36
// #include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

ull cycleCount(int i) {
    ull r = 1;
    while (i > 1) {
        if (i % 2 == 0) i = i/2;
        else i = (3 * i) + 1;
        r++;
    }
    return r;
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i, j;
    ull mCount{0};

    while(cin >> i >> j) {
        mCount = cycleCount(min(i,j));
        for (int k = min(i,j) + 1; k < max(i,j) + 1; k++) {
            ull cCount = cycleCount(k);
            mCount = max(cCount, mCount);
        }
        cout << i << ' ' << j << ' ' << mCount << endl;
    }
}

