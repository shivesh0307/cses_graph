#include<bits/stdc++.h>
using namespace std;
#define PRIME 1000000007
#define MOD 1000000009
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll long long int
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define sz(c) c.size()
#define r(i,a,b)    for(i=a;i<b;i++)
#define ra(i,a,b)   for(i=a;i<=b;i++)
#define vi vector<int>
#define vil vector<ll>
void dfs(ll i,vector<vector<ll> > &edges, ll src[])
{
    if(src[i]) return ;
    src[i]=1;
    for(ll j=0;j<edges.size();j++)
    {
      ll u=edges[j][0];
         ll v=edges[j][1];
         if(v==i)
         {
             dfs(u,edges,src);
         }
    }
    return ;
}
ll solve()
{
  ll n,m; ll i,j;
  cin>>n>>m;
  vector<vector<ll> > edges;
  vector<ll> temp(3);
  ll dist[n+1]; ll src[n+1];
  for(i=0;i<n+1;i++)
  {
     dist[i]=LLONG_MAX;
     src[i]=0;
  }
  dist[1]=0;
  for(i=0;i<m;i++)
  {
    cin>>temp[0]>>temp[1]>>temp[2];
    temp[2]*=-1;
    edges.pb(temp);
 
  }
  for(i=0;i<n-1;i++)
  {
      for(j=0;j<edges.size();j++)
      {
         ll u=edges[j][0];
         ll v=edges[j][1];
         ll w=edges[j][2];
         if(dist[u]!=LLONG_MAX && (dist[v]>dist[u]+w))
         {
          dist[v]=dist[u]+w;
         }
      }
  }
  //vil vis(n+1,0);
  dfs(n,edges,src);
  for(j=0;j<edges.size();j++)
      {
         ll u=edges[j][0];
         ll v=edges[j][1];
         ll w=edges[j][2];
         if(dist[u]!=LLONG_MAX && (dist[v]>dist[u]+w))
         {
             if(src[v])
             {
          cout<<-1; return 0;
             }
             //dist[v]=dist[u]+w;
         }
      }
      cout<<-dist[n];
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