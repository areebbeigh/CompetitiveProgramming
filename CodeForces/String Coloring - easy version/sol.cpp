// http://codeforces.com/contest/1296/problem/E1
#include <bits/stdc++.h>
#include <cassert>

typedef unsigned long long ull;
typedef unsigned long ul;

using namespace std;

class Node {
    public:
    char letter;
    int idx;
    bool color = false;
    vector<Node*> dependencies;
    
    Node(char ltr, int idx) {
        this->letter = ltr;
        this->idx = idx;
    }

    bool operator== (const Node &other) {
        return letter == other.letter and idx == other.idx;
    }

    void addDependency(Node *node) {
        assert(!count(dependencies.begin(), dependencies.end(), node));
        dependencies.push_back(node);
        // cout << dependencies.size() << endl;
    }
};

// Checks if a node's dependency path exceeds given max depth
bool checkDepDepth(Node *node, int maxDepth=1) {
    if (maxDepth < 0) return false;
    for(auto n : node->dependencies) {
        n->color = !node->color;
        if (!checkDepDepth(n, maxDepth-1)) return false;
    }
    return true;
}

int main(int argc, const char** argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x;
    cin >> x;
    string chars;
    cin >> chars;
    vector<Node> nodes;
    for(int i = 0; i < chars.length() ; i++) {
        nodes.push_back(Node(chars.at(i), i));
    }
    for (int i1 = 0; i1 < nodes.size(); i1++) {
        Node &n1 = nodes.at(i1);
        for (int i2 = i1 + 1; i2 < nodes.size(); i2++) {
            Node &n2 = nodes.at(i2);
            if (n2.letter < n1.letter) {
                n1.addDependency(&n2);
            }
        }
    }
    string colors;
    for(auto &n : nodes) {
        if (!checkDepDepth(&n, 1)) {
            cout << "NO" << endl;
            return 0;
        }
        colors.push_back(n.color ? '1' : '0');
    }
    cout << "YES" << endl << colors << endl;
}

