/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_2413.cpp
Code by : acident / lckintrovert
Created since : 21/08/2023 ~~ 16:28:06
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define vvi                 vector< vector<int> >
#define endl                '\n'
#define pb                  emplace_back
#define pf                  push_front
#define all(a)              a.begin(), a.end()
#define mp                  make_pair
#define YES                 cout << "YES\n";
#define NO                  cout << "NO\n";
#define ins                 insert
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e6 + 10;
int const INF       =       1e18;
 
int n, dp[maxn][3] = {};
void solve() {
    cin >> n;
    dp[1][1] = 1; // [][]
    dp[1][2] = 1; // [__]
    for(int i = 2; i <= n; i++) {
        dp[i][1] = 4 * dp[i - 1][1] + dp[i - 1][2];
        dp[i][2] = dp[i - 1][1] + 2 * dp[i - 1][2];
        dp[i][1] %= mod;
        dp[i][2] %= mod;    
    }
    int ans = dp[n][1] + dp[n][2];
    ans = (ans + mod * mod) % mod;
    cout << ans << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}
