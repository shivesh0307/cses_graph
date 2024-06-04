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

int movi[4] = {1, 0, -1, 0};
int movj[4] = {0, 1, 0, -1};
int n, m,k;
/*int dfs(int i , int j) {
    visited[i][j]=true;
    if(i==n-1 || j==m-1) return true; 
    for(int k=0;k<4;k++)
    {
            int newi = i+movi[k];
            int newj = j+movj[k];
            if(min(newi,newj)>=0 && newi<n && newj<m && arr[newi][newj]=='.' && !visited[newi][newj] && distA[newi][newj]<distM[newi][newj])
            {
                switch(k)
                {
                    case 0:
                    ans.push_back('D');
                    break ; 
                    case 1:
                    ans.push_back('R');
                    break ; 
                    case 2:
                    ans.push_back('U');
                    break ; 
                    case 3:
                    ans.push_back('L');
                    break ; 
                }
               if(dfs(newi,newj))
               {
                  return true;  
               }
               ans.pop_back();
            } 
    }
    return false;
}
*/
void solve() {
    cin >> n >> m >>k;
    int a, b,c; 
    vector<pair<ll,ll>> adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    //vector<ll> dist(n+1,INFL);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>> , greater<pair<ll,ll>> > pq;
    priority_queue<ll> best[n+1];
    //dist[1]=0; instead of dist , we keep bes
    pq.push({0,1});
    best[1].push(0);
    while(pq.size())
    {
        auto node = pq.top(); pq.pop();
        ll u = node.second;
        ll cost=node.first;
        //if(node.first != dist[node.second]) continue;
        if(cost>best[u].top()) continue;
        for(auto neighbor: adj[node.second])
        {
            ll v= neighbor.first; ll w= neighbor.second; 
            ll totcost= cost+w;
            if(best[v].size()<k)
            {
                best[v].push(totcost);
                pq.push({totcost,v});
            }
            else if(totcost<best[v].top())
            {
                best[v].pop();
                best[v].push(totcost);
                pq.push({totcost,v});
            }
        }
        
    }
    vector<ll> ans;
     while(best[n].size())
     {
         ans.push_back(best[n].top()); best[n].pop();
     }
     reverse(ans.begin(),ans.end());
     for(int i=0;i<ans.size();i++) cout<<ans[i] << " ";
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
