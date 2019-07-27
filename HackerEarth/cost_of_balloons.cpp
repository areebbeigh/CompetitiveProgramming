#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    int t;
    cin >> t;

    while (t--) {
        int cG, cP, cT1{0}, cT2{0}, n;
        cin >> cG;
        cin >> cP;
        cin >> n;
        while (n--) {
            int i, j;
            cin >> i;
            cin >> j;
            if (i) {
                cT1 += cP;
                cT2 += cG;
            }
            if (j) {
                cT1 += cG;
                cT2 += cP;
            }
        }
        cout << min(cT1, cT2) << '\n';
    }
}

