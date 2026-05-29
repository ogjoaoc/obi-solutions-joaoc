// dijkstra
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e18;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 2>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<int> dp(n + 1, INF);
    dp[1] = 0;
    priority_queue<array<int, 2>> pq;
    pq.push({0, 1});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        d = -d;
        if (d > dp[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (d + w < dp[v]) {
                dp[v] = d + w;
                pq.push({-dp[v], v});
            }
        }
    }
    cout << dp[n] << '\n';
}