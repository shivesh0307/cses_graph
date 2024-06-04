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
#define INF 1e9+1

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

    vector<int> parent(n + 1,-1);
    queue<int> q; q.push(1); //parent[1]=0;
    while(q.size())
    {
        int node = q.front(); q.pop(); 
        for(int neighbor : adj[node])
        {
            if(parent[neighbor]==-1 && neighbor!=1)
            {
                parent[neighbor]=node; 
                q.push(neighbor);
            }
        }
    }
    if(parent[n]==-1) {
        cout<<"IMPOSSIBLE";
        return ; 
    }
    vector<int> path; 
    int end = n ; 
    while(end!=-1)
    {
        path.push_back(end);
        end = parent[end];
    }
    cout<<path.size()<<endl;
    reverse(path.begin(), path.end());

    for(int i=0;i<path.size();i++)
    {
        cout<<path[i]<<" ";
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
