/*
Good luck for those who are trying your best
May the most glorious victory come
File name: usaco_dp_phidias.cpp
Code by : acident / lckintrovert
Created since : 05/08/2023 ~~ 16:18:29
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
int const maxn      =       800;
int const INF       =       1e18;
 
int W, H, n;
int dp[maxn][maxn] = {};
int w[maxn] = {}, h[maxn] = {};
void solve() {
    cin >> W >> H >> n;
    for(int i = 1; i <= W; i++) for(int j = 1; j <= H; j++) dp[i][j] = i * j;
    for(int i = 1; i <= n; i++) {
        cin >> w[i] >> h[i];
        dp[w[i]][h[i]] = 0;
    }
    for(int i = 1; i <= W; i++) {
        for(int j = 1; j <= H; j++) {
            for(int k = 1; k <= i; k++) {
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j]);
            }
            for(int k = 1; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k]);
            }
        }
    }
    cout << dp[W][H] << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}