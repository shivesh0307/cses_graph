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
vector<ll> adj[MAXN];
vector<ll> coins(MAXN);
vector<vector<ll>> comp;
vector<int> disc(MAXN,-1);
vector<int> low(MAXN,-1);
vector<bool> stackMember(MAXN,false);
stack<ll> st;
ll n,m;
ll idx=0;
map<ll,ll> scc;
map<ll,ll> scc_coins;
ll tim=0;
void dfs(int u)
{
    // Initialize discovery time and low value
    disc[u] = low[u] = ++tim;
    st.push(u);
    stackMember[u] = true;
 
    // Go through all vertices adjacent to this
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i; // v is current adjacent of 'u'
 
        // If v is not visited yet, then recur for it
        if (disc[v] == -1) {
            dfs(v);
 
            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 (per above discussion on Disc and Low
            // value)
            low[u] = min(low[u], low[v]);
        }
 
        // Update low value of 'u' only of 'v' is still in
        // stack (i.e. it's a back edge, not cross edge).
        // Case 2 (per above discussion on Disc and Low
        // value)
        else if (stackMember[v] == true)
            low[u] = min(low[u], disc[v]);
    }
 
    // head node found, pop the stack and print an SCC
    int w = 0; // To store stack extracted vertices
    vector<ll> ans; 
    if (low[u] == disc[u]) {
        while (st.top() != u) {
            w = (int)st.top();
            ans.push_back(w);
            stackMember[w] = false;
            st.pop();
            scc[w]=idx;
            scc_coins[idx]+=coins[w];
        }
        w = (int)st.top();
        ans.push_back(w);
        scc[w]=idx;
        scc_coins[idx]+=coins[w];
        comp.push_back(ans);
        idx++;
        stackMember[w] = false;
        st.pop();
    }
}
ll dfs2(ll u,vector<ll> &dp_coins)
{
    if(dp_coins[u]!=0) return dp_coins[u];
    ll mx=0; map<int,int> vis;
    dp_coins[u]+=scc_coins[u];
    for(int i=0;i<comp[u].size();i++)
    {
        ll node = comp[u][i];
        for(int j=0;j<adj[node].size();j++)
        {
        int v= scc[adj[node][j]];
        if(vis[v]==0 && v!=u)
        {
            vis[v]++;
            mx=max(mx,dfs2(v,dp_coins));
        }
        }
    }
    dp_coins[u]+=mx;
    return dp_coins[u];
}
ll solve()
{
    ll x,k,y;
    cin>>n>>m;
    for(int i=1;i<n+1;i++) cin>>coins[i];
    for(int i=0;i<m;i++)
    {
     cin>>x>>y;
     adj[x].push_back(y);
    }
    
    for(int i=1;i<n+1;i++)
    {
        if(disc[i]==-1)
        dfs(i);
    }
    /*for(int i=0;i<idx;i++)
    {
        for(int j=0;j<comp[i].size();j++)
        {
            cout<<comp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    //for(int i=0;i<idx;i++) cout<<scc_coins[i]<<" ";
    //cout<<endl;
    vector<ll> dp_coins(idx,0);
    ll mx=0; 
    for(int i=0;i<idx;i++)
    {
        if(dp_coins[i]==0)
        {
        ll x= dfs2(i,dp_coins);
        }
        //cout<<dp_coins[i]<<" ";
        mx=max(mx,dp_coins[i]);
    }
    //cout<<endl;
    
    cout<<mx;
    
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