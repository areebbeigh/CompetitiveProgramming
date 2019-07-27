// https://www.hackerearth.com/challenges/competitive/july-circuits-19/algorithm/superbalancedbracket-75edd495/
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t--) {
        string s;
        getline(cin, s);
        vector<int> o;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') o.push_back(i);
        }
        int r = 0;
        int li = s.size() - 1;
        for(auto k : o) {
            bool found = false;
            for (int i = li; i > k; i--) {
                if (s[i] == ')') {
                    r += 1;
                    li = i - 1;
                    found = true;
                    break;
                }
            }
            if (!found) break;
        }
        
        cout << r * 2 << endl;
        // for continuous subsequences -_-
        // vector<int> o;
        // int r = 0; // sbbs
        // int sl = 0; // temp sbbs
        // int n = 0;
        // bool afterOpening;

        // for (int i = 0; i < s.size(); i++) {
        //     char c = s[i];
            
        //     if (i == 0) o.push_back(0);

        //     if (c == '(' && (afterOpening || i == 0)) {
        //         afterOpening = true;
        //         o[n] += 1;
        //     }

        //     else if (c == '(' && !afterOpening) {
        //         n += 1;
        //         o.push_back(1);
        //         afterOpening = true;
        //         sl = 0;
        //     }

        //     if (c == ')' && o[o.size() - 1] != 0) {
        //         afterOpening = false;
        //         o[o.size() - 1] -= 1;
        //         sl += 1;
        //         r = max(r, sl);
        //         // cout << "here " << endl;
        //     }
        // }
        // r *= 2;
        // cout << r << endl;
    }
}

