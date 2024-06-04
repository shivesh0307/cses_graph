#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define PRIME 1000000009
#define endl '\n'
#define pb push_back
#define F first
#define S second
#define ll  long long
#define ull  unsigned int
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(c) c.size()
#define r(i, a, b) for(i = a; i < b; i++)
#define ra(i, a, b) for(i = a; i <= b; i++)
#define vi vector<int>
#define vil vector<ll>

int movi[4] = {1, 0, -1, 0};
int movj[4] = {0, 1, 0, -1};
int n, m;

void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &arr) {
    if (visited[i][j]) return;
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        int newi = i + movi[k];
        int newj = j + movj[k];

        if (min(newi, newj) >= 0 && newj < m && newi < n && arr[newi][newj] == '.') {
            dfs(newi, newj, visited, arr);
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && arr[i][j] == '.') {
                dfs(i, j, visited, arr);
                cnt++;
            }
        }
    }
    cout << cnt << endl;
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
