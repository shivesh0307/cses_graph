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
ll n,m; 
vector<ll> adj[501];
vil parent(501,-1);
ll cap[501][501];
ll reachability()
{
    queue<ll> q; q.push(1);
    fill(parent.begin(), parent.end(), -1);
    parent[1]=1;
    while(q.size())
    {
        ll u = q.front(); q.pop();
        for(auto v:adj[u])
        {
            
            if(parent[v]==-1 && cap[u][v]>0)
            {
                parent[v]=u;
                q.push(v);
            }
        }
    }
    return parent[n]==-1?0:1;
}
// Main solving function
ll solve() {
    cin>>n>>m;
    ll x,y;
   for(int i=0;i<m;i++)
   {
       cin>>x>>y;
       adj[x].push_back(y);
       adj[y].push_back(x);
       cap[x][y]+=1;
       cap[y][x]+=1;
   }
   
   while(reachability())
   {
      ll flow=INT_MAX;
      ll v=n;
      while(v!=1)
      {
          ll u= parent[v];
          flow=min(flow,cap[u][v]);
          v=u;
      }
      
      v=n;
      while(v!=1)
      {
          ll u= parent[v];
          cap[u][v]-=flow;
          cap[v][u]+=flow;
          v=u;
      }
   }
   reachability();
   vector<pair<ll,ll>> ans;
   for(int  i=1;i<n+1;i++)
   {
       for(int j:adj[i])
       {
           if(parent[i]!=-1 && parent[j]==-1)
           {
               ans.push_back({i,j});
           }
       }
   }
   cout<<ans.size()<<endl;
   for(int i=0;i<ans.size();i++)
   {
       cout<<ans[i].first<<" "<<ans[i].second<<endl;
   }
   
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
