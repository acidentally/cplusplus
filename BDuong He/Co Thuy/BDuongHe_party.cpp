/*
Good luck for those who are trying your best
May the most glorious victory come
File name: BDuongHe_party.cpp
Code by : acident / lckintrovert
Created since : 05/08/2023 ~~ 09:19:56
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
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, m;
pi a[maxn] = {};
int dp[maxn] = {};
int check[maxn] = {};
int track[maxn] = {};
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
        check[i] = -1;
    }
    dp[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(check[a[i].fi] == -1) {
            check[a[i].fi] = 0;
            dp[i] = dp[i + 1] + 1;
        } else if(check[a[i].fi] == 0) {
            check[a[i].fi] = 1;
            dp[i] = dp[i + 1];
        } else {
            dp[i] = dp[i + 1];
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dp[i] << endl;
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}