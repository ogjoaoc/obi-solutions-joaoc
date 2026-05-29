// brute-force com next_permutation()
#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int N;
    cin >> N;
    map<vector<int>, bool> mp;
    vector<int> f(N + 1);
    f[0] = f[1] = 1;
    for (int i = 2; i <= N; i++) {
        f[i] = f[i - 1] * i;
    }
    for (int i = 0; i < f[N]; i++) {
        vector<int> v(N);
        for (int &x : v) cin >> x;
        mp[v] = true;
    }
    vector<int> perm;
    for (int i = 1; i <= N; i++) {
        perm.push_back(i);
    }
    do {
        if (!mp[perm]) {
            for (int x : perm) cout << x << ' ';
            return 0;
        }
    } while(next_permutation(begin(perm), end(perm)));
    return 0;
}