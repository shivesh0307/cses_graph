#include <bits/stdc++.h>
using namespace std;

#define PRIME 1000000007
#define MOD 1000000009
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long int
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(c) c.size()
#define r(i, a, b) for(i = a; i < b; i++)
#define ra(i, a, b) for(i = a; i <= b; i++)
#define vi vector<int>
#define vil vector<ll>

ll n, m, source, sink; 
vector<ll> adj[1002];
vil parent(1002, -1);
ll cap[1002][1002];

ll reachability() {
    queue<ll> q;
    q.push(source);
    fill(parent.begin(), parent.end(), -1);
    parent[source] = source;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        for (ll v=source;v<=sink;v++) {
            if (parent[v] == -1 && cap[u][v] > 0) {
                parent[v] = u;
                if (v == sink) {
                    return 1;
                }
                q.push(v);
            }
        }
    }
    return 0;
}

// Main solving function
ll solve() {
    ll x, y, k;
    cin >> n >> m >> k;

    source = 0;  sink = n + m + 1;
    memset(cap, 0, sizeof(cap)); // Initialize capacities to 0

    for (int i = 0; i < k; i++) {
        cin >> x >> y; 
        y = y + n;
        if(!cap[x][y])
        adj[x].push_back(y);
        cap[x][y] = 1;
        cap[source][x] = 1;
        cap[y][sink] = 1;
    }

    ll max_flow = 0;

    while (reachability()) {
        ll flow = INT_MAX;
        ll v = sink;
        while (v != source) {
            ll u = parent[v];
            flow = min(flow, cap[u][v]);
            v = u;
        }

        v = sink;
        while (v != source) {
            ll u = parent[v];
            cap[u][v] -= flow;
            cap[v][u] += flow;
            v = u;
        }

        max_flow += flow;
    }

    cout << max_flow << endl;
    
    for(ll b=1;b<=n;b++)
    {
        for(ll g: adj[b])
        {
            if(cap[b][g]==0)
            {
                cout<<b<<" "<<g-n<<endl;
            }
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
