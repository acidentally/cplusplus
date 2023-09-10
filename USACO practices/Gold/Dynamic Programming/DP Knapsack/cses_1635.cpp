/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1635.cpp
Code by : acident / lckintrovert
Created since : 05/08/2023 ~~ 17:26:39
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
int const maxn      =       1e6 + 3;
// int const INF       =       1e18;
 
int n, x, u;
vi c;
int dp[maxn];
void solve() {
    cin >> n >> x;
    while(n--) {
        cin >> u;
        c.pb(u);
    }
    sort(all(c));
    dp[0] = 1;
    for(int i = 1; i <= x; i++) {
        for(int j : c) {
            if(i - j < 0) break;
            (dp[i] += dp[i - j]) %= mod;
        }
    }
    cout << (dp[x] % mod);
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}