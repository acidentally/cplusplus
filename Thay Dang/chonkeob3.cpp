/*
Good luck for those who are trying your best
May the most glorious victory come
File name: chonkeob3.cpp
Code by : acident / lckintrovert
Created since : 18/08/2023 ~~ 15:39:28
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
 
int n;
int a[maxn] = {}, dp[maxn][3] = {};
void solve() {
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    // cerr << sum;}
    dp[1][0] = 0;
    dp[1][1] = a[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j <= 2; j++) dp[i][0] = max(dp[i][0], dp[i - 1][j]);
        dp[i][1] = a[i] + dp[i - 1][0];
        dp[i][2] = a[i] + dp[i - 1][1];
    }
    int ans = 0;
    for(int i = 0; i <= 2; i++) ans = max(ans, dp[n][i]);
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}