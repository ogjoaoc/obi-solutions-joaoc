// dp com otimização 
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // map<pair<int, int>, int> dp;
    vector<vector<int>> dp(N + 1);
    for (int i = 1; i <= N; i++) {
        sort(begin(adj[i]), end(adj[i]));
        dp[i].resize(adj[i].size(), -1ll);
    }
    auto dfs = [&](auto && dfs, int u, int j) -> int {
        if (j == adj[u].size()) return 0;
        if (~dp[u][j]) return dp[u][j];
        int ans = dfs(dfs, u, j + 1);
        int v = adj[u][j];
        int nj = upper_bound(begin(adj[v]), end(adj[v]), u) - begin(adj[v]);
        ans = max(ans, dfs(dfs, v, nj) + 1);
        return dp[u][j] = ans;
    };
    for (int i = 1; i <= N; i++) {
        cout << dfs(dfs, i, 0) + 1 << ' ';
    }
    cout << '\n';
    return 0;
}