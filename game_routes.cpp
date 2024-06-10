#include<bits/stdc++.h>
using namespace std;
#define PRIME 1000000007
#define MOD 1000000009
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll  int
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define sz(c) c.size()
#define r(i,a,b)    for(i=a;i<b;i++)
#define ra(i,a,b)   for(i=a;i<=b;i++)
#define vi vector<int>
#define vil vector<ll>
ll solve()
{
   ll i,j,n,m; ll x;
  cin>>n>>m;
  vil adj[n+1];
  vil in(n+1,0);
  for(i=0;i<m;i++)
  {
      ll u,v; cin>>u>>v;
      adj[u].pb(v);
      in[v]++;
  }
  vil dist(n+1,0); queue<ll> q; 
  vil par(n+1, -1); 
  for(i=1;i<n+1;i++)
  {
      if(in[i]==0)
      {
       q.push(i);   
      }
  }
  dist[1]=1;
  while(q.size())
  {
  ll u=q.front(); q.pop();
  for(i=0;i<adj[u].size();i++)
  {
      ll v=adj[u][i]; 
      dist[v]+=dist[u];
      dist[v]%=PRIME;
      in[v]--;
      if(in[v]==0) q.push(v);
  }
  }
  /*if(dist[n]==0) 
  {
      cout<<"IMPOSSIBLE"; return 0; 
  }*/
  cout<<(dist[n])<<endl;
 return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}