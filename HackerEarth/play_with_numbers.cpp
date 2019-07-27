// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/play-with-numbers-2/
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n;
    cin >> q;
    long long arr[n];
    long long sums[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i==0) sums[0] = arr[0];
        else sums[i] = arr[i] + sums[i-1];
    }
    while (q--) {
        int l, r;
        cin >> l;
        cin >> r;
        long long sum = 0;
        if (l > 1) {
            sum = sums[r-1] - sums[l-2];
        } else {
            sum = sums[r-1];
        }
        cout << sum / (r-l+1) << '\n';
    }
}

