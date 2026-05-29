// código antigo
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define iii tuple<int, int, int> 
#define mp make_pair
#define int long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define _ ios::sync_with_stdio(false); cin.tie(0);
    
const int MAXN = 101;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const int MOD = 1e9+7;
    
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
int l, c;
        
bool check(int i, int j) {
    return (i < l && i >= 0 && j < c && j >= 0 && mat[i][j] != '.' && !vis[i][j]);
}
    
void solve() {
    
    cin >> l >> c;
    
    
    pii pos_inicial;
    for(int i=0; i<l; i++) {
        for(int j=0; j<c; j++) {
            cin >> mat[i][j];
            if(mat[i][j] == 'o') pos_inicial = {i, j};
        }
    }
    pii cara_atual;
    stack<pii> pilha;
    pilha.push(pos_inicial);
    
    while(!pilha.empty()) {
    
        auto atual = pilha.top();
        pilha.pop();
        vis[atual.ff][atual.ss] = true;
        cara_atual = mp(atual.ff, atual.ss);
        
        
        if(check(atual.ff+1, atual.ss) && mat[atual.ff+1][atual.ss] == 'H') { // baixo
            pilha.push({atual.ff+1, atual.ss});
        }	
        if(check(atual.ff-1, atual.ss) && mat[atual.ff-1][atual.ss] == 'H') { // cima
            pilha.push({atual.ff-1, atual.ss});
        }
        if(check(atual.ff, atual.ss-1) && mat[atual.ff][atual.ss-1] == 'H') {
            pilha.push({atual.ff, atual.ss-1});
        }
        if(check(atual.ff, atual.ss+1) && mat[atual.ff][atual.ss+1] == 'H') {
            pilha.push({atual.ff, atual.ss+1});
        }
    }
    
    cout << cara_atual.ff+1 << ' ' << cara_atual.ss+1 << "\n";

}
    
int32_t main() {_ 
    
    int tt = 1;
    while(tt--) {
        solve();
    }
    
}
