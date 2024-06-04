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

int movi[4] = {1, 0, -1, 0};
int movj[4] = {0, 1, 0, -1};
int n, m;
vector<char> ans;
char arr[1001][1001];
int distM[1001][1001];
int distA[1001][1001];
bool visited[1001][1001];

bool dfs(int i, int j) {
    visited[i][j] = true;
    if (i == 0 || j == 0 || i == n-1 || j == m-1) return true;
    for (int k = 0; k < 4; k++) {
        int newi = i + movi[k];
        int newj = j + movj[k];
        if (min(newi, newj) >= 0 && newi < n && newj < m && arr[newi][newj] == '.' && !visited[newi][newj] && distA[newi][newj] < distM[newi][newj]) {
            switch (k) {
                case 0: ans.push_back('D'); break;
                case 1: ans.push_back('R'); break;
                case 2: ans.push_back('U'); break;
                case 3: ans.push_back('L'); break;
            }
            if (dfs(newi, newj)) {
                return true;
            }
            ans.pop_back();
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            distM[i][j] = INF;
            distA[i][j] = INF;
        }
    }

    queue<pair<int, int>> q1, q2;
    int startX, startY;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 'M') {
                distM[i][j] = 0;
                q1.push({i, j});
            } else if (arr[i][j] == 'A') {
                distA[i][j] = 0;
                startX = i;
                startY = j;
                q2.push({i, j});
            }
        }
    }

    while (!q1.empty()) {
        auto node = q1.front(); q1.pop();
        int x = node.first, y = node.second;
        for (int k = 0; k < 4; k++) {
            int newi = x + movi[k];
            int newj = y + movj[k];
            if (newi >= 0 && newi < n && newj >= 0 && newj < m && arr[newi][newj] == '.' && distM[newi][newj] == INF) {
                distM[newi][newj] = distM[x][y] + 1;
                q1.push({newi, newj});
            }
        }
    }

    while (!q2.empty()) {
        auto node = q2.front(); q2.pop();
        int x = node.first, y = node.second;
        for (int k = 0; k < 4; k++) {
            int newi = x + movi[k];
            int newj = y + movj[k];
            if (newi >= 0 && newi < n && newj >= 0 && newj < m && arr[newi][newj] == '.' && distA[newi][newj] == INF) {
                distA[newi][newj] = distA[x][y] + 1;
                q2.push({newi, newj});
            }
        }
    }

    if (dfs(startX, startY)) {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (char c : ans) {
            cout << c;
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
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
