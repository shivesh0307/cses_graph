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
map<int, vector<int>> adj;
vector<int> disc(MAXN,-1);
vector<int> low(MAXN,-1);
vector<bool> stackMember(MAXN,false);
stack<int> st;
int tim=0;
vector<vector<int>> comp; 
int idx=0;
ll n,m;
void dfs(int u)
{
    // Initialize discovery time and low value
    disc[u+m] = low[u+m] = ++tim;
    st.push(u);
    stackMember[u+m] = true;
 
    // Go through all vertices adjacent to this
    for (auto i = adj[u].begin(); i != adj[u].end(); ++i) {
        int v = *i; // v is current adjacent of 'u'
 
        // If v is not visited yet, then recur for it
        if (disc[v+m] == -1) {
            dfs(v);
 
            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 (per above discussion on Disc and Low
            // value)
            low[u+m] = min(low[u+m], low[v+m]);
        }
 
        // Update low value of 'u' only of 'v' is still in
        // stack (i.e. it's a back edge, not cross edge).
        // Case 2 (per above discussion on Disc and Low
        // value)
        else if (stackMember[v+m] == true)
            low[u+m] = min(low[u+m], disc[v+m]);
    }
 
    // head node found, pop the stack and print an SCC
    int w = 0; // To store stack extracted vertices
    vector<int> ans;
    if (low[u+m] == disc[u+m]) {
        while (st.top() != u) {
            w = (int)st.top();
            ans.push_back(w);
            stackMember[w+m] = false;
            st.pop();
        }
        w = (int)st.top();
        ans.push_back(w);
        comp.push_back(ans);
        idx++;
        stackMember[w+m] = false;
        st.pop();
    }
}
ll solve()
{
    ll x,k,y;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        char ch1, ch2; 
        cin>>ch1>>x>>ch2>>y;
        if(ch1=='-') x=x*-1; 
        if(ch2=='-') y=y*-1;
        adj[-x].push_back(y);
        adj[-y].push_back(x);
    }
    auto it = adj.begin(); 
    while(it!=adj.end()){
        if(disc[it->first+m]==-1)
        {
            dfs(it->first);
        }
        it++;
    }
    vector<int> val(m+1,-1);
    for(int i=0;i<idx;i++)
    {
        map<int,int> vis; 
        for(int j=0;j<comp[i].size();j++)
        {
            if(vis[abs(comp[i][j])])
            {
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
            vis[abs(comp[i][j])]=1;
            if(val[abs(comp[i][j])]==-1)
            {
            if(comp[i][j]<0) val[abs(comp[i][j])]=0;
            else val[abs(comp[i][j])]=1;
                
            }
        }
    }
    for(int i=1;i<m+1;i++) cout<<(val[i]?"+":"-")<<" ";
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