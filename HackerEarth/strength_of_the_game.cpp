// https://www.hackerearth.com/challenges/competitive/july-circuits-19/algorithm/xor-thingy-36fea7be/
#include <bits/stdc++.h> 
 
typedef unsigned long long ull;
typedef unsigned long ul;
 
using namespace std;
 
int mostSigBit(int n) {
    int p = 0;
    while (n) {
        n >>= 1;
        p += 1;
    }
    return p;
}
 
void countWays(int m, int rIdx, vector<vector<int>> ranges, ull &ways, int rShift) {
    // for (int i = 0; i < ranges.size(); i++) {
    //     // cout << "here" << endl;
    //     vector<int> &r2 = ranges[i];
    //     cout << ":: " << r2.size() << endl;
    //     for (auto x : ranges[i]) {
    //         cout << x << endl;
    //     }
    // }
    // cout << "here" << endl;
    // return;
    for(auto n : ranges[rIdx]) {
        // cout << n << endl;
        // cout << n << " " << m << " " << (m^n) << endl;
        int n2 = n >> rShift;
        if (rIdx == ranges.size() - 1) {
            // cout << "here" << endl;
            if ((m^n2) == 0) ways += 1;
            continue;
        }
        countWays(m^n2, rIdx + 1, ranges, ways, rShift);
    }
    
    // for (int n = 0; n <= ranges[rIdx]; n++) {
    //     // cout << m << " ^ " << n << " = " << (m^n) << endl;
    //     int n2 = n >> rShift;
    //     // if (rIdx == ranges.size() - 2) {
    //     //     int x = ranges[ranges.size() - 1] >> rShift;
    //     //     // cout << "x : " << x <<  endl;
    //     //     if ((m^n2) <= x) {
    //     //         // cout << "adding " << endl;
    //     //         ways += 1;
    //     //     }
    //     //     continue;
    //     // }
    //     if (rIdx == ranges.size() - 1) {
    //         if ((m^n2) == 0) {
    //             ways += 1;
    //         }
    //         continue;
    //     }
    //     countWays(m^n2, rIdx + 1, ranges, ways, rShift);
    // }
}

void countWaysUtil(int m, vector<vector<int>> &r) {
    ull ways = 0;
    countWays(m, 0, r, ways, 0);
    cout << ways << endl;
    for (int i = 0; i <= 512; i++) {
        if (m & (1<<i) != 0) {
            int m2 = m >> (i + 1) << 1;
            // vector<int> r2;
            // for(auto x : r) {
            //     r2.push_back(x >> i);
            // }
            countWays(m2, 0, r, ways, i);
        }
    }
    cout << ways << ' ';
    // cout << endl; 
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> r(n, vector<int>());
    // r.resize(n, vector<int>(n, 0));
    // cout << r[2].size() << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        // r[i] = vector<int>();
        for (int k = 0; k <= x; k++) {
            r[i].push_back(k);
        }
    }
    // for (int i = 0; i < r.size(); i++) {
    //     // cout << "here" << endl;
    //     vector<int> &r2 = r[i];
    //     cout << ":: " << r2.size() << endl;
    //     for (int j = 0; j < r2.size(); j++) {
    //         cout << r2[j] << endl;
    //     }
    // }
    // cout << "here" << endl;
    // sort(r.begin(), r.end());
    // for (int i = 0; i <= m; i++) {
    //     ull ways = 0;
    //     countWays(i, 0, r, ways);
    //     ways = ways % 1000000007;
    //     cout << ways << ' ';
    // }
    // for (int i = 0; i <= m; i++) {
    //     countWaysUtil(i, r);
    // }
    for (int i = 0; i <= m; i++) {
        ull ways = 0;
        countWays(i, 0, r, ways, 0);
        cout << ways << ' ';
    }
    
    cout << endl;
}

