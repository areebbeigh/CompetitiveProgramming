// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=778
// #include <iostream>
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    // ostream fcout (cout.rdbuf());
    // fcout  << fixed << setprecision(3);
    cout  << fixed << setprecision(3);

    struct line {
        double x1, y1, x2, y2, r;
    };

    while (t--) {
        int n;
        cin >> n;

        vector<line> lines;
        vector<double> xCoods;

        while (n--) {
            double x1, x2, y1, y2, r;
            cin >> x1 >> y1 >> x2 >> y2 >> r;
            
            xCoods.push_back(x1);
            xCoods.push_back(x2);

            line l = { x1, y1, x2, y2, r };
            lines.push_back(l);
        }

        sort(xCoods.begin(), xCoods.end());

        int x = 1 + xCoods.size();
        cout << x << endl;

        cout << "-inf " << xCoods[0] << " " << 1.0 << endl;
        for (int i = 0; i < xCoods.size() - 1; i++) {
            double R = 1;
            double x1 = xCoods[i];
            double x2 = xCoods[i + 1];
            // cout << x1 << " " << x2 << "--" << endl;

            for (int j = 0; j < lines.size(); j++) {
                line l = lines[j];
                double lx1 = min(l.x1, l.x2);
                double lx2 = max(l.x1, l.x2);
                // cout << "line:: " << l.x1 << " " << l.x2 << " " << l.r << endl;
                if ((lx1 >= x1 && lx1 < x2) || (lx2 <= x2 && lx2 > x1) || (lx1 <= x1 && lx2 >= x2) ) {
                    // cout << l.x1 << " " << l.x2 << " " << l.r << endl;
                    R *= l.r;
                }
            }
            cout << x1 << ' ' << x2 << ' ' << R << endl;
        }
        cout << xCoods[xCoods.size() - 1] << " " << "+inf " << 1.0 << endl;
        if (t) cout << endl;
    }
}

