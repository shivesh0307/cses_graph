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
vector<int> ans;
int dfs(int node , vector<int> &state, vector<int> &visited,vector<ll> adj[])
{
    if(state[node]==1)
    {
        return node; 
    }
    if(visited[node]==1) return 0 ;
     state[node]=1;
     ans.push_back(node);
     for(auto neighbor : adj[node])
     {
         ll x= dfs(neighbor,state,visited,adj);
         if(x)
         return x; 
     }
     ans.pop_back();
     visited[node]=1;
     state[node]=0;
     return 0 ; 
    
}
void solve() {
    cin >> n >> m ;
    int a, b,c; 
    vector<ll> adj[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    vector<int> state(n+1,0);
    vector<int> visited(n+1,0);
    for(int i=1;i<n+1;i++)
    {
        if(visited[i]==0) 
        {
            ll x= dfs(i,state,visited,adj);
            if(x)
            {
                ll index=-1;
                for(int j=0;j<ans.size();j++)
                {
                    if(ans[j]==x)
                    {
                        index= j ; break;
                        
                    }
                }
                cout<<ans.size()-index+1<<endl;
                for(int j=index;j<ans.size();j++)
                cout<<ans[j]<<" ";
                cout<<ans[index];
                return ; 
            }
        }
        
    }
    cout<<"IMPOSSIBLE";
    
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
