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
   ll i,j,n,m,q; ll x,k;
    cin>>n>>q;
    ll dp[n+1][32];
    memset(dp,0,sizeof(dp));
    for(i=1;i<n+1;i++)
    {
        cin>>dp[i][0];
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
      cin>>x>>k;
      for(i=0;i<32;i++)
      {
          if((1<<i)&k)
          {
              x=dp[x][i];
          }
      }
      cout<<x<<endl;
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