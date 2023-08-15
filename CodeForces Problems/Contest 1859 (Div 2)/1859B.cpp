/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1859B.cpp
Code by : acident / lckintrovert
Created since : 12/08/2023 ~~ 21:48:13
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
int const maxn      =       3e4 + 10;
int const INF       =       1e9;
 
int n, m, x;
pi a[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> m;
        a[i].se = a[i].fi = INF;
        for(int j = 1; j <= m; j++) {
            cin >> x;
            a[i].se = min(a[i].se, x);
            if(a[i].fi > a[i].se) swap(a[i].fi, a[i].se);
        }
    }
    sort(a + 1, a + n + 1);
    int dp[n + 10][2] = {};
    if(n == 1) {
        cout << a[1].fi << endl;
        return;
    }
    dp[1][0] = a[1].fi;
    dp[1][1] = a[1].se;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][1] + min(a[i].fi, a[i - 1].fi), dp[i - 1][0] + a[i].fi);
        dp[i][1] = max(dp[i - 1][1] + min(a[i].se, a[i - 1].fi), dp[i - 1][0] + a[i].se);
    }

    // dp[1][0] = dp[n][1] + min(a[n].fi, a[1].fi) - a[1].fi;
    // dp[1][1] = max(dp[n][1] + min(a[n].fi, a[1].se) - a[1].se, dp[1][0]);

    cout << max(dp[n][0], dp[n][1]) << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}