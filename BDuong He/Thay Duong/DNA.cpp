/*
Good luck for those who are trying your best
May the most glorious victory come
File name: DNA.cpp
Code by : acident / lckintrovert
Created since : 12/08/2023 ~~ 10:06:59
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
bool a[maxn] = {};
int dp[maxn][2] = {};
void solve() {          
    cin >> n;
    for(int i = 1; i <= n; i++) {
        char c; cin >> c;
        a[i] = c - 'A';
    }
    //a[i] == 0 : A, a[i] == 1 : B
    dp[n][0] = a[1];
    dp[n][1] = 1 + !a[1];
    for(int i = n - 1; i >= 1; i--) {
        dp[i][0] = dp[i + 1][0] + a[i];
        dp[i][1] = min(dp[i + 1][1], dp[i + 1][0]) + 1 + !a[i];
    }
    cout << min(dp[1][0], dp[1][1]);
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("DNA.INP", "r", stdin);
    // freopen("DNA.OUT", "w", stdout);
    solve();
}