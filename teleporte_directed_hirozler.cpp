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
ll n, m;
const int MAXN = 200005;
set<ll> adj[MAXN];
vector<ll> inEdges(MAXN,0);
vector<ll> outEdges(MAXN,0);
vector<ll> ans;
vector<bool> vis(MAXN,false);
void dfs(ll u)
{
    vis[u]=true;
    while(adj[u].size())
    {
        auto v= adj[u].begin();
        outEdges[u]--; inEdges[*v]--;
        adj[u].erase(v);
        dfs(*v);
        
    }
    ans.push_back(u);
}
ll solve()
{
    ll x,k,y;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
     cin>>x>>y;
     adj[x].insert(y);
     inEdges[y]++;
     outEdges[x]++;
    }
    if(outEdges[1]-inEdges[1]!=1 || inEdges[n]-outEdges[n]!=1)
    {
        //cout<<"here1"<<endl;
        cout<<"IMPOSSIBLE";
        return 0;   
    }
    for(int i=2;i<n;i++)
    {
        if(inEdges[i]!=outEdges[i])
        {
            //cout<<"here2"<<endl;
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    dfs(1);
    for(int i=2;i<n+1;i++)
    {
        if(adj[i].size() && !vis[i])
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    
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