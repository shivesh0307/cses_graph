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
 const int MAXN = 200005;
 vector<ll> vis(MAXN,0);
 vector<ll> path_len(MAXN,0);
 queue<ll> q; 
 vector<ll> next_node(MAXN,0);
 void dfs(ll i,ll &steps)
 {
     q.push(i);
     if(vis[i])
     {
         steps+=path_len[i]; 
         return ;
     }
     vis[i]=1;
     steps+=1;
     dfs(next_node[i],steps);
 }
ll solve()
{
   ll n,m; ll x,k,y;
    cin>>n;
    for(int i=1;i<n+1;i++)
    {
        cin>>next_node[i];
    }
    for(int i=1;i<n+1;i++)
    {
        if(!vis[i])
        {
         ll steps =0 ;    
         dfs(i,steps);
         ll decrement = -1 ;
         while(q.size())
         {
             ll node= q.front(); 
             if(q.front()==q.back()) decrement=0;
             q.pop();
             path_len[node]= steps; 
             steps+=decrement; 
         }
        }
    }
    for(int i=1;i<n+1;i++)
    cout<<path_len[i]<<" ";
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