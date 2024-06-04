#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define PRIME 1000000009
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define ll long long
#define ull unsigned int
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(c) c.size()
#define r(i, a, b) for(i = a; i < b; i++)
#define ra(i, a, b) for(i = a; i <= b; i++)
#define vi vector<int>
#define vil vector<ll>

int movi[4] = {1, 0, -1, 0};
int movj[4] = {0, 1, 0, -1};
int n, m;

void dfs(int node, vector<int> adj[], vector<bool> &visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

void solve() {
    cin >> n >> m;
    int a, b;
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    vector<int> nodes;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            nodes.pb(i);
        }
    }

    cout << nodes.size() - 1 << endl;
    for (int i = 0; i < nodes.size() - 1; i++) {
        cout << nodes[i] << " " << nodes[i + 1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
