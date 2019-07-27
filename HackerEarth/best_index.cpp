#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <string>
#include <sstream>
#include <array>

using namespace std;


int main(int argc, const char** argv) {
    int t, t2;
    cin >> t;
    t2 = t;
    vector<int> arr;
    vector<long> sum;
    sum.reserve(t);
    arr.reserve(t);
    while (t2--) {
        int x;
        cin >> x;
        arr.push_back(x);
        if (t2 == t-1) {
            sum.push_back(arr[0]);
        }
        else {
            sum.push_back(sum[sum.size() - 1] + x);
        }
        // cout << arr[arr.size() - 1] << ' ' << sum[sum.size() - 1] << endl;
    }

    long maxSpecialSum = INT64_MIN;

    for (int i = arr.size() - 1; i >= 0; i--) {
        int n = i;
        int a{2};

        while (true) {
            if (n+a >= t) break;
            n += a;
            a++;
        }

        long specialSum = sum[n] - ((i == 0) ? 0 : sum[i - 1]);
        maxSpecialSum = max(specialSum, maxSpecialSum);
    }

    cout << maxSpecialSum << '\n';
}

