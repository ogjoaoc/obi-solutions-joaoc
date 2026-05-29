// código antigo
#include <bits/stdc++.h>
using namespace std;
// #ifndef ONLINE_JUDGE
// #include "debug.h"
// #else
// #define db(...)
// #endif
#define int long long
const int INF = 1e18;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  int f = 0, s = 0;
  while(n--) {
    int a, b;
    cin >> a >> b;
    if (b == (a + 1)%5 || b == (a + 2)%5) {
      f++;
    } else if(a == (b + 1)%5 || a == (b + 2)%5) {
      s++;
    }
  }
  if (s > f) cout << "xerxes\n";
  else cout << "dario\n";
} 

/* Notas  
  
  a + b = a ^ b + 2 * (a & b)

*/