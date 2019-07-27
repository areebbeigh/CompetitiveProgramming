// #include <iostream>
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int checkWins(const char &c, char grid[3][3]) {
    int r = 0;
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == c && grid[i][1] == c && grid[i][2] == c) r += 1;
        if (grid[0][i] == c && grid[1][i] == c && grid[2][i] == c) r += 1;
    }
    if (grid[0][0] == c && grid[1][1] == c && grid[2][2] == c) r += 1;
    if (grid[0][2] == c && grid[1][1] == c && grid[2][0] == c) r += 1;
    return r;
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    cin.ignore(37627, '\n');
    while (t--) {
        string l;
        char grid[3][3];
        int r = 0;
        int n = 3;
        int xC{0}, oC{0};
        while (n--) {
            cin >> l;
            for (int i = 0; i < 3; i++) {
                grid[r][i] = l[i];
                if (l[i] == 'X') xC += 1;
                if (l[i] == 'O') oC += 1;
            }
            r++;
        }

        int oWin = checkWins('O', grid);
        int xWin = checkWins('X', grid);
        bool valid = true;
        // cout << oWin << " " << xWin << endl;

        if (oC > xC) {
            // cout << 1 << endl;
            valid = false;
        }
        else if (xC - oC > 1 || xC - oC < 0) {
            valid = false;
        }
        else if ((oWin > 1 || xWin > 1) && (xC - oC > 1 || xC - oC < 0)) {
            valid = false;
        }
        // O wins, xC = oC & X loses
        else if (oWin == 1 && (xC != oC || xWin > 0)) {
            // cout << 2 << endl;
            valid = false;
        }
        // X wins, xC > oC & O loses
        else if (xWin == 1 && (xC != oC + 1 || oWin > 0)) {
            // cout << 3 << endl;
            valid = false;
        }

        if (valid) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

        // for(char *a : grid) {
        //     for (int i = 0; i < 3; i++) {
        //         cout << *(a+i) << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
}

