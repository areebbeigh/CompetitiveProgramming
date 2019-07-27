// https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/lift-queries/description/

#include <iostream>

using namespace std;

int main(int argc, const char** argv) {
    int A{0}, B{7};
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if (abs(n-A) < abs(B-n)) {
            cout << "A";
            A = n;
        }
        else if (abs(n-A) > abs(B-n)) {
            cout << "B";
            B = n;
        } else {
            if (A < B) {
                cout << "A";
                A = n;
            } else {
                cout << "B";
                B = n;
            }
        }
        cout << endl;
    }
}

