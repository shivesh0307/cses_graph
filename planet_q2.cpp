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
 ll dp[MAXN][32];
 vector<ll> vis(MAXN,0);
 vector<ll> len(MAXN,0);
 ll lift(ll x, ll d)
 {
     if(d<=0) return x; 
     ll p=0;
     while(p<32)
     {
         if((1<<p)&d)
         {
             x=dp[x][p];
         }
         p++;
     }
     return x; 
 }
 void dfs(ll i)
 {
     vis[i]=1;
     if(!vis[dp[i][0]])
     dfs(dp[i][0]);
     
     len[i]=len[dp[i][0]]+1;
 }
ll solve()
{
   ll i,j,n,m,q; ll x,k,y;
    cin>>n>>q;
    memset(dp,0,sizeof(dp));
    for(i=1;i<n+1;i++)
    {
        cin>>dp[i][0];
    }
    for(int i=1;i<n+1;i++)
    {
        if(!vis[i])
        dfs(i);
    }
    for(j=1;j<32;j++)
    {
    for(i=1;i<n+1;i++)
    {
        {
            dp[i][j]=dp[dp[i][j-1]][j-1];
        }
    }
    }
    
    while(q--)
    {
      cin>>x>>y;
      ll xx= lift(x,len[x]);
      ll ans=-1 ; 
      if(lift(x,len[x]-len[y])==y)
      ans=len[x]-len[y];
      else if (lift(xx,len[xx]-len[y])==y)
      ans=len[x]+len[xx]-len[y];
      cout<<ans<<endl;
    }
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