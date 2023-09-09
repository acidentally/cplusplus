/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1690.cpp
Code by : acident / lckintrovert
Created since : 09/09/2023 ~~ 10:08:33
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)
 
//#define _USE_MATH_DEFINES // If meth .__.
 
template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
 
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       (1 << 20) + 50;
int const INF       =       1e18;
 
int n, m, u, v;
int dp[30][maxn] = {};
vi a[30];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        a[v].pb(u);
    }
    dp[0][0] = 1;
    n--;
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i <= n; i++) {
            if(mask & (1 << i)) continue;
            for(auto u : a[i]) {
                if((mask & (1 << u)) && !(mask & (1 << i))) {
                    (dp[i][mask] += dp[u][mask ^ (1 << u)]) %= mod;
                }
            }
        }
    }   
    // n--;
    cout << dp[n][(1 << n) - 1];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/