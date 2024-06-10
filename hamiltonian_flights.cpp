#include<bits/stdc++.h>
using namespace std;
#define PRIME 1000000007
#define endl '\n'
#define ll  long long 
 
const int MAXN = 20;
//vector<ll> adj[MAXN];
vector<int> radj[MAXN]; //radj[u]={v,w}  v-->u; w-->u;
ll dp[1<<20][20];
int n,m;
ll solve()
{
    int x,k,y;
    cin>>n>>m;
    //memset(dp,0, sizeof(dp));
    for(int i=0;i<m;i++)
    {
     cin>>x>>y; x--; y--;
     //x-->y
     //adj[x].push_back(y);
     radj[y].push_back(x);
    }
    dp[1][0]=1;
    int subsets = (1<<n)-1;
    int last_point=(1<<(n-1));
    for(int s=2; s<=subsets;s++)
    {
        if((s&(1<<0)) ==0) continue;
        // also only consider subsets with the last city if it's the full subset
		if ((s & last_point) && (s != subsets)) continue;
        for(int j=0;j<n;j++)
        {
            if(s&(1<<j)==0) 
            {
                continue;
            }
            int mask=s^(1<<j);
            for(int k :radj[j])
            {
                if ((s & (1 << k))) {
                dp[s][j]+=dp[mask][k];
                dp[s][j]%=PRIME;
                }
            }
        }
    }
    cout<<dp[(1<<n)-1][n-1];
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
