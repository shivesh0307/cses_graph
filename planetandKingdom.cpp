#include<bits/stdc++.h>
using namespace std;
#define PRIME 1000000007
#define MOD 1000000009
#define endl '\n'
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ll  long long int 
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define sz(c) c.size()
#define r(i,a,b)    for(i=a;i<b;i++)
#define ra(i,a,b)   for(i=a;i<=b;i++)
#define vi vector<int>
#define vil vector<ll>

const int MAXN = 200005;
vil adj[MAXN];
vil radj[MAXN];
vil visited(MAXN,0);
vil comp(MAXN,-1);
vil order; 
void dfs(ll node)
{
    if(visited[node]) return;
    visited[node]=1;
    for(auto v : adj[node])
    {
            dfs(v);
    }
     order.push_back(node);
}
void dfs2(ll node , ll c)
{
    if(comp[node]!=-1) return;
    comp[node]=c;
    for(auto v : radj[node])
    {
            dfs2(v,c);
    }
}
ll solve()
{
   ll n,m; ll x,k,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y; adj[x].push_back(y);
        radj[y].push_back(x);
    }
    for(int i=1;i<n+1;i++)
    {
        if(!visited[i])
        dfs(i);
    }
    reverse(order.begin(),order.end());
    ll c=1; 
    for(int i=0;i<n;i++)
    {
        if(comp[order[i]]==-1)
        {
            dfs2(order[i],c);
            c++;
        }
    }
    cout<<c-1<<endl;
    for(int i=1;i<n+1;i++)
    cout<<comp[i]<<" ";
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