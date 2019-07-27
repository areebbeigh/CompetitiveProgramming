// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1222
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string i;
    double d = 0;
    double s = 0;
    double oldParams[4]{0};
    for(auto &x : oldParams) {
        x = -1;
    }

    cout << fixed << setprecision(2);

    while (getline(cin, i)) {
        // cout << i << endl;
        int n = 0;
        double params[4];
        for(auto &x : params) {
            x = -1;
        }
        stringstream sStream;
        for(char c : i) {
            // cout << c << " ";
            if (c != ' ' && c != ':') {
                // cout << "pushing " << c << " " << x << endl;
                sStream << c;
            } else {
                // cout << "hit " << c << endl;
                sStream >> params[n];
                sStream.clear();
                n++;
            }
        }
        sStream >> params[n];
        sStream.clear();

        // for(auto p : params) {
        //     cout << p << ' ';
        // }
        // cout << endl;
        double h = params[0] + params[1] / 60.0 + params[2] / 3600.0;
        double hOld;
        if (oldParams[0] > -1) hOld = oldParams[0] + oldParams[1] / 60.0 + oldParams[2] / 3600.0;
        else hOld = 0;
        d += s * abs(hOld - h);

        if (params[3] == -1) {
            cout << i.substr(0, 9) << " " << d << " km" << endl;
        }
        if (params[3] != -1) s = params[3];
        copy(params, params + 4, oldParams);
    }
}

