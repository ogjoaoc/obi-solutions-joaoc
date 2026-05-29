// inclusão e exclusão + brute
#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<int> p(K);
    for (int &x : p) cin >> x;
    sort(begin(p), end(p));
    int ans = 0;
    auto rec = [&](auto && rec, int i, int prod, int cnt) -> void {
        if (prod > N) return;
        if (i == K) {
            if (cnt & 1) ans += prod;
            else ans -= prod;
        }
        rec(rec, i + 1, prod * p, cnt + 1);
        rec(rec, i + 1, prod, cnt);
    };
}