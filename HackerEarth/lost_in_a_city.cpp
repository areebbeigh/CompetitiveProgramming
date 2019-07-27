// https://www.hackerearth.com/challenges/competitive/july-circuits-19/algorithm/lost-in-city-f6e7f540/
#include <bits/stdc++.h> 
 
typedef unsigned long long ull;
typedef unsigned long ul;
 
using namespace std;

unordered_map<int, forward_list<int>> roads;
vector<int> v;
vector<int> visited;

void computeV(int s, int d, int p, int &pFinal) {
    visited.push_back(s);
    int vi = v[s - 1];
    p = max(vi, p);
    if (s == d) {
        pFinal = p < pFinal ? p : pFinal;
        visited.pop_back();
        return;
    }
    unordered_map<int, forward_list<int>>::iterator it = roads.find(s);
    if (it == roads.end()) return;
    for(auto &c : it->second) {
        if (find(visited.begin(), visited.end(), c) == visited.end()) {
            computeV(c, d, p, pFinal);
        }
    }
    visited.pop_back();
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t; 
    while (t--) {
        int n, m, s;
        cin >> n >> m >> s;
        v.reserve(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        
        roads.insert({s, forward_list<int>{}});
        while (m--) {
            int a, b;
            cin >> a >> b;
            unordered_map<int, forward_list<int>>::iterator it = roads.find(a);
            // vector<int> &c;
            if (it != roads.end()) {
                it->second.push_front(b);
            } else {
                // cout << "new road" << a << " " << b << endl;
                roads.insert({a, forward_list<int>{b}});
            }
        }

        for (int i = 1; i <= n; i++) {
            int p = INT_MAX;
            // cout << "s: " << s << " i: " << i << endl;
            computeV(s, i, INT_MIN, p);
            cout << p << ' ';
        }
        cout << endl;
        // for (map<int, vector<int>>::iterator it = roads.begin(); it != roads.end(); it++) {
        //     cout << it->first << ' ';
        //     for(auto c : it->second)
        //     {
        //         cout << c << ' ';
        //     }
        //     cout << endl;
        // }
        v.clear();
        roads.clear();
    }
}

// class TreeN {
// public:
//     int d;
//     vector<TreeN> chld;
 
//     bool operator==(const TreeN &o) {
//         return o.d == d;
//     }
// };
 
// vector<int> v;
 
// void addNode(TreeN &root, int &from, int &to) {
//     if (root.d == from) {
//         root.chld.push_back(TreeN{to});
//         // cout << "f: " << from << " t: " << to << " p: " << root.d << endl;
//     }
//     else {
//         for(auto &c : root.chld) {
//             addNode(c, from, to);
//         }
//     }
// }
 
// void printTree(TreeN &root) {
//     cout << root.d << ":" << endl;
//     for(auto c : root.chld) {
//         cout << c.d << ' ';
//     }
//     cout << endl;
//     for(auto c : root.chld) {
//         printTree(c);
//     }
// }
 
// void computeV(TreeN &s, int d, int o, int &oFinal) {
//     // cout << s.d << endl;
//     int vi = v[s.d - 1];
//     o = max(vi, o);
//     if (s.d == d) {
//         // oFinal.push_back(o);
//         oFinal = o < oFinal ? o : oFinal;
//         return;
//     }
//     if (s.chld.size() == 0) return;
//     for(auto c : s.chld) {
//         computeV(c, d, o, oFinal);
//     }
// }
 
// int main(int argc, const char** argv) {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t; 
//     while (t--) {
//         int n, m, s;
//         cin >> n >> m >> s;
//         v.reserve(n);
//         for (int i = 0; i < n; i++) {
//             int x;
//             cin >> x;
//             v.push_back(x);
//         }
//         TreeN c = {s, vector<TreeN>{}};
//         while (m--) {
//             int a, b;
//             cin >> a >> b;
//             addNode(c, a, b);
//         }
//         for (int i = 1; i <= n; i++) {
//             // vector<int> p;
//             int p = INT_MAX;
//             computeV(c, i, INT_MIN, p);
//             cout << p << ' ';
//             // cout << *min_element(p.begin(), p.end()) << ' ';
//         }
//         cout << endl;
//         // printTree(c);
//         v.clear();
//     }
// }
 
