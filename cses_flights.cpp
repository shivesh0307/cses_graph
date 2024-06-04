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
#define INFL 1e16

int n, m,q;
void solve() {
    cin >> n >> m;
    int a, b,c; 
    vector<vector<ll>> adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    vector<vector<ll>> dist(n+1,vector<ll>(2,INFL));
    priority_queue<vector<ll>,vector<vector<ll>> , greater<vector<ll>> > pq;
    dist[1]={0,0};  //0-->without discount 1-->with discount
    pq.push({0,0,1}); //0-->cost 1-->discount or not 2-->node
    while(pq.size())
    {
        auto node = pq.top(); pq.pop();
        if(node[0] != dist[node[2]][node[1]]) continue;
        for(auto neighbor: adj[node[2]])
        {
           if(node[1]) //discount used
           {
             if(dist[neighbor[0]][1]>dist[node[2]][1]+neighbor[1])   
             {
                 dist[neighbor[0]][1]=dist[node[2]][1]+neighbor[1];
                 pq.push({dist[neighbor[0]][1],1,neighbor[0]});
             }
           }
           else if(node[1]==0)
           {
              if(dist[neighbor[0]][1]>dist[node[2]][0]+(neighbor[1]/2))   
             {
                 dist[neighbor[0]][1]=dist[node[2]][0]+(neighbor[1]/2);
                 pq.push({dist[neighbor[0]][1],1,neighbor[0]});
             }
             if(dist[neighbor[0]][0]>dist[node[2]][0]+(neighbor[1]))   
             {
                 dist[neighbor[0]][0]=dist[node[2]][0]+(neighbor[1]);
                 pq.push({dist[neighbor[0]][0],0,neighbor[0]});
             }
           }
        }
    }
    cout<<min(dist[n][0],dist[n][1]);
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
