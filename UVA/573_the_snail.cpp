// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=514
// #include <iostream>
#include <bits/stdc++.h> 

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    float h,u,d,f;
    while (cin>>h>>u>>d>>f) {
        if (h == 0) return 0;

        float i = (float)h;
        float ff = (f/100.0) * u;
        int day = 0;

        while (i >= 0) {
            // printf("-- %d\n", day);
            // printf("-- %f %f %f %f\n", i, u, d, f);
            i -= u > 0 ? u : 0;
            i += i >= 0 ? d : 0;
            u -= ff;
            day++;
            if (i > h) break;
        }

        if (i <= 0) cout << "success on day " << day << endl;
        else cout << "failure on day " << day << endl;
    }
}

