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
int n, m,q;
ll dist[500+1][500+1];
/*int dfs(int i , int j) {
    visited[i][j]=true;
    if(i==n-1 || j==m-1) return true; 
    for(int k=0;k<4;k++)
    {
            int newi = i+movi[k];
            int newj = j+movj[k];
            if(min(newi,newj)>=0 && newi<n && newj<m && arr[newi][newj]=='.' && !visited[newi][newj] && distA[newi][newj]<distM[newi][newj])
            {
                switch(k)
                {
                    case 0:
                    ans.push_back('D');
                    break ; 
                    case 1:
                    ans.push_back('R');
                    break ; 
                    case 2:
                    ans.push_back('U');
                    break ; 
                    case 3:
                    ans.push_back('L');
                    break ; 
                }
               if(dfs(newi,newj))
               {
                  return true;  
               }
               ans.pop_back();
            } 
    }
    return false;
}
*/
void solve() {
    cin >> n >> m >>q;
    int a, b,c; 
    vector<pair<ll,ll>> adj[n+1];
    for(int i =1; i<n+1;i++)
        {
            for(int j =1 ;j<n+1;j++)
            {
                if(i==j)
                {
                    dist[i][j]=0; continue;
                }
                dist[i][j]=INFL;
            }
        }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        dist[a][b]=min(dist[a][b],(ll)c);
        dist[b][a]=min(dist[b][a],(ll)c);
    }
    for(int k = 1;k<n+1;k++)
    {
        for(int i =1; i<n+1;i++)
        {
            for(int j =1 ;j<n+1;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--)
    {
        cin>>a>>b; 
        cout<<(dist[a][b]==INFL ? -1 : dist[a][b])<<endl;
    }
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
