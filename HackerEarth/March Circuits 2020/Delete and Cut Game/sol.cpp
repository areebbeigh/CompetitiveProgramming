// #include <iostream>
#include <bits/stdc++.h>

typedef unsigned long long ull;
typedef unsigned long ul;
typedef long long ll;

using namespace std;

ll N, M;

class Node
{
    public:
    ll data;
    ll x = 0; // this holds the component count if I'm part of an edge.
    ll num, low;
    Node* parent = NULL;
    vector<Node*> nodes;

    Node(ll d) : data(d) {}
};

class Graph
{
    public:
    ll counter = 0;
    unordered_map<ll, Node*> nodes;
    vector<pair<ll, ll>> components;

    void addEdge(ll a, ll b)
    {
        if (nodes.find(a) == nodes.end())
        {
            nodes[a] = new Node(a);
        }
        if (nodes.find(b) == nodes.end())
        {
            nodes[b] = new Node(b);
        }
        nodes[a]->nodes.push_back(nodes[b]);
        nodes[b]->nodes.push_back(nodes[a]);
    }

    void bridgesHelper(Node* v, unordered_set<Node*>& visited)
    {
        if (visited.find(v) != visited.end()) return;
        visited.insert(v);
        v->num = counter;
        v->low = counter;
        counter++;
        v->x = 1;

        for(auto& w : v->nodes)
        {
            if (visited.find(w) == visited.end())
            {
                w->parent = v;
                bridgesHelper(w, visited);
                v->x += w->x;
                v->low = min(v->low, w->low);

                if (w->low > v->num)
                {
                    assert(0 < w->x < N);
                    components.push_back({N - w->x, w->x});
                }
            }
            else
            {
                if (v->parent != w)
                {
                    v->low = min(v->low, w->num);
                }
            }
        }
    }

    void findBridges()
    {
        unordered_set<Node*> visited;
        auto nodesIt = nodes.begin();
        bridgesHelper(nodesIt->second, visited);
        assert(nodesIt->second->x == N);
    }

    ll countComponentsHelper(Node* node1, Node* node2, unordered_set<Node*>& visited)
    {
        visited.insert(node1);
        ll rv = 1;
        for(auto w : node1->nodes)
        {
            if (w == node2 || visited.find(w) != visited.end()) continue;
            rv += countComponentsHelper(w, node2, visited);
        }
        return rv;
    }

    pair<ll, ll> countComponents(Node* node1, Node* node2, ll N)
    {
        unordered_set<Node*> visited;
        ll c1 = countComponentsHelper(node1, node2, visited);
        return {c1, N-c1};
    }
};

ll gcdExtended(ll a, ll b, ll *x, ll *y);

// Function to find modulo inverse of b. It returns
// -1 when inverse doesn't
ll modInverse(ll b, ll m)
{
    ll x, y; // used in extended GCD algorithm
    ll g = gcdExtended(b, m, &x, &y);

    // Return -1 if b and m are not co-prime
    if (g != 1)
        return -1;

    // m is added to handle negative x
    return (x%m + m) % m;
}

// Function to compute a/b under modlo m
ll modDivide(ll a, ll b, ll m)
{
    a = a % m;
    ll inv = modInverse(b, m);
    if (inv == -1)
       throw exception();
    else
       return (inv * a) % m;
}

// C function for extended Euclidean Algorithm (used to
// find modular inverse.
ll gcdExtended(ll a, ll b, ll *x, ll *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    ll x1, y1; // To store results of recursive call
    ll gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

ll m = 1000000007;
int main(int argc, const char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll N, M;
    cin >> N >> M;
    Graph graph;
    while (M--)
    {
        ll a, b;
        cin >> a >> b;
        graph.addEdge(a, b);
    }
    graph.findBridges();

    ll aWins = 0, bWins = 0;
    for(auto& c : graph.components)
    {
        assert(c.first + c.second == N);
        if (c.first % 2 == 0 && c.second % 2 == 0) aWins++;
        else bWins++;
    }
    ll t = aWins + bWins;
    if (t == 0) cout << 0 << " " << 0 << endl;
    else cout << modDivide(aWins, t, m) << " " << modDivide(bWins, t, m) << endl;
}

