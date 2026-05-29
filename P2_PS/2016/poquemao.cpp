// código antigo, deve fugir do estilo dos outros :/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ff first
#define ss second
#define endl "\n"
#define all(x) x.begin(), x.end()
#define pb push_back
#define pii pair<int, int>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const int MOD = 998244353;
const int MAX = 2e5+1;



void solve() { 

	int n; 
	cin >> n;

	vector <int> v(3);

	for (int i = 0; i < 3; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int total = 0, ans = 0;
	int i = 0;

	while (i < 3) {
		
		total += v[i];
		// dbg cout << "Atual: " << total << "\n";
		
		if (total <= n) ans++;

		i++;
	}

	cout << ans << "\n";

}


signed main() { _ 
    
    int t = 1; // cin >> t;
    while(t--) 
        solve();
 
    return 0;
}