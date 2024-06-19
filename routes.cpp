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
ll cap[1002][1002], ocap[1002][1002];
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
    cin >> n >> m;

    source = 1;  sink = n;
    memset(cap, 0, sizeof(cap)); // Initialize capacities to 0

    for (int i = 0; i < m; i++) {
        cin >> x >> y; 
        if(!cap[x][y])
        adj[x].push_back(y);
        cap[x][y] += 1;
    }

    vector<vector<ll>>  flows;
    ll ans=0;
    while (reachability()) {
        //vector<ll> ans;
        ll flow = 1;
        ll v = sink;
        //cout<<"v "<<v<<endl;
        while (v != source) {
            //ans.push_back(v);
            ll u = parent[v];
            flow = min(flow, cap[u][v]);
            v = u;
        }
        //ans.push_back(v);
        v = sink;
        while (v != source) {
            ll u = parent[v];
            cap[u][v] -= flow;
            cap[v][u] += flow;
            v = u;
        }

        //reverse(ans.begin(),ans.end());
        //flows.push_back(ans);
        ans++;
    }
    cout<<ans<<endl; set<pair<ll,ll>> edges;
    for(ll i=0;i<ans;i++)
    {
        vil path;
        ll source=1;
        path.push_back(source);
        while(source!=n)
        {
            for(ll child:adj[source])
            {
                if(cap[source][child]==0 && edges.find({source,child})==edges.end())
                {
                    path.push_back(child);
                    edges.insert({source,child});
                    source=child;
                    break;
                }
            }
        }
        cout<<path.size()<<endl;
        for(ll j=0;j<path.size();j++)
        {
            cout<<path[j]<<" ";
        }
        cout<<endl;
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
