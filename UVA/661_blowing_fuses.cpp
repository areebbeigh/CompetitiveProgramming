// #include <iostream>
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c;
    int t = 0;

    while (cin >> n >> m >> c) {
        if (n == 0) return 0;
        int amps[n];
        int status[n];
        fill_n(status, n, -1);
        t++;

        int tc = 0, max_tc = 0;
        bool blown = false;

        for (int i = 0; i < n; i++) {
            cin >> amps[i];
        }

        for (int i = 0; i < m; i++) {
            int op;
            cin >> op;
            if (blown == true) continue;

            // cout << "--- " << status[op - 1] << endl;

            if (status[op - 1] == -1) {
                tc += amps[op - 1];
                status[op - 1] = 1;
            } else {
                tc -= amps[op - 1];
                status[op - 1] = -1;
            }

            max_tc = max(tc, max_tc);
            // cout << "--- " << tc << " - " << max_tc << ' ' << status[op - 1] << endl;

            if (tc > c) {
                blown = true;
            }
        }
        
        cout << "Sequence " << t << endl;
        if (blown) cout << "Fuse was blown." << endl;
        else {
            cout << "Fuse was not blown." << endl;
            // printf("Maximal power consumption was %d amperes.", max_tc);
            cout << "Maximal power consumption was " << max_tc << " amperes." << endl;
        }
        cout << endl;
    }
}

