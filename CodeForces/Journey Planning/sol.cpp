// http://codeforces.com/contest/1320/problem/A
#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

int main()
{
    ull n;
    cin >> n;
    vector<ull> cities(n);
    unordered_map<ull, ull> sums;
    ull res = 0;
    for (ull i = 0; i < n; i++)
    {
        ull b;
        cin >> b;
        if (sums.find(b-i) == sums.end())
        {
            sums[b-i] = 0;
        }
        sums[b-i] += b;
        res = max(sums[b-i], res);
    }
    cout << res << endl;
}