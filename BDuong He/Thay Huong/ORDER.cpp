/*
Good luck for those who are trying your best
May the most glorious victory come
File name: ORDER.cpp
Code by : acident / lckintrovert
Created since : 07/08/2023 ~~ 09:21:28
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
int const maxn      =       1e4 + 10;
int const INF       =       1e18;
 
int n, c;
int dp[maxn][maxn] = {};
void solve() {
    cin >> n >> c;
    // f(n, c) = f(n - 1, c) + ... + f(n - 1, c - n + 1);
    // f(n, k) [k <= n] =
    
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("ORDER.INP", "r", stdin);
    // freopen("ORDER.OUT", "w", stdout);
    solve();
}