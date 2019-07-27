// https://www.hackerearth.com/challenges/competitive/july-circuits-19/algorithm/strange-xor-13414ed5/
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int mod = 1000000007;

ul power(int x, int y, int m) {
    if (y == 0) return 1;
    ul p = power(x, y/2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (p * x) % m;
}

int modInv(int a) {
    return power(a, mod - 2, mod);
}

typedef unordered_map<int, vector<int>> Memo;
Memo memo;

void compute(int s, int n, int k, vector<int> &res) {
    for (int i = 0; i < n + 1; i++) {
        if (k == 1) {
            res.push_back(s ^ i);
        }
        else {
            compute(s^i, n, k-1, res);
        }
    }
}

int computeUtil(int s, int n, int k) {
    vector<int> res;
    bool fromMemo = false;
    Memo::iterator it = memo.find(n);
    if (it != memo.end()) {
        // cout << "yo";
        int km = it->second[0];
        if (km < k) fromMemo = true;
    } else {
        res.push_back(k);
    }

    if (fromMemo) {
        vector<int> &r = it->second;
        int km = r[0];
        res.push_back(k);
        for (int i = 1; i < r.size(); i++){
            compute(r[i], n, k - km, res);
        }
    }
    else {
        compute(0, n, k, res);
        memo[n] = res;
    }

    int sum{0};
    for (int i = 1; i < res.size(); i++) {
        sum += s^res[i];
    }
    return sum;
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n, k, s;
        cin >> n >> k >> s;
        // int res{0};        
        int p = pow(n+1, k);
        int sum = computeUtil(s, n, k);
        ul mmi = modInv(p) % mod;
        ul x =  mmi * sum;
        // cout << x << endl;
        cout << x % mod << endl;
    }
}

