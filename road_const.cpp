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
 vil parent(MAXN);
 vil c_size(MAXN,1);
 ll mx=1; 
 ll cmp;
 ll find(ll x)
 {
     if(parent[x]!=x)
     {
         parent[x]= find(parent[x]);
     }
     return parent[x];
 }
 ll unionp(ll x, ll y)
 {
    ll px= find(x); 
    ll py= find(y);
    if(px==py) return max(c_size[px],c_size[py]);
    
    if(c_size[px]>c_size[py])
    {
        parent[py]=px;
        c_size[px]+=c_size[py];
        return c_size[px];
    }
        parent[px]=py;
        c_size[py]+=c_size[px];
        return c_size[py];
 }
ll solve()
{
   ll n,m; ll x,k,y;
    cin>>n>>m;
    cmp= n; 
    for(int i=1;i<n+1;i++) parent[i]=i;
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        ll px=find(x); 
        ll py= find(y);
        if(px!=py)
        {
            mx=max(mx,unionp(px,py));
            cmp--;
        }
        cout<<cmp<<" "<<mx<<endl;
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