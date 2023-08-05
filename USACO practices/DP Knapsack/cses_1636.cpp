/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1636.cpp
Code by : acident / lckintrovert
Created since : 05/08/2023 ~~ 17:50:20
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
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
int const maxn      =       1e6 + 1;
 
#pragma optimization ("Ofast")

int n, x, temp;
int c[110], dp[maxn + 10][110] = {};
void solve() {
    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> c[i];  
    }
    sort(c, c + n);
    dp[0][0] = 1;
   
    for(int i = 0; i < x; i++) {
        for(int j = 0; (j < n) && (i + c[j] <= x); j++) {
            (dp[i][j + 1] += dp[i][j]) %= mod;
            (dp[i + c[j]][j] += dp[i][j]) %= mod;
        }
    }
    for(int j = 0; j < n - 1; j++) {
        (dp[x][j + 1] += dp[x][j]) %= mod;
    }
    cout << dp[x][n - 1];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}