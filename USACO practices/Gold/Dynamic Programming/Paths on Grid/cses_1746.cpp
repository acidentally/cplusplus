/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1746.cpp
Code by : acident / lckintrovert
Created since : 23/08/2023 ~~ 17:59:39
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
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, m, a[maxn] = {};
int dp[maxn][110] = {};
void solve() {
    cin >> n >> m;
    cin >> a[1];
    if(a[1] == 0) {
        for(int i = 1; i <= m; i++) dp[1][i] = 1;
    } else dp[1][a[1]] = 1;
    for(int i = 2; i <= n; i++) {
        cin >> a[i];
        if(a[i] != 0) {
            for(int j = max(1ll, a[i] - 1); j <= min(m, a[i] + 1); j++) {
                (dp[i][a[i]] += dp[i - 1][j]) %= mod;
            } continue;
        }

        for(int j = 1; j <= m; j++) {
            for(int k = max(1ll, j - 1); k <= min(m, j + 1); k++) {
                (dp[i][j] += dp[i - 1][k]) %= mod;
            }
        }
       
    }
    for(int i = 1, ans = 0; i <= m; i++) {
        (ans += dp[n][i]) %= mod;
        if(i == m) {
            cout << ans;
            return;
        }
    } 
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/