/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1158.cpp
Code by : acident / lckintrovert
Created since : 06/08/2023 ~~ 18:14:48
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
 
int n, x;
int h[2000] = {}, s[2000] = {}, dp[maxn] = {};
void solve() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = x ; j >= 0; j--) {
            if(j - h[i] >= 0) dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    // for(int i = 1; i <= x; i++) cerr << i << ' ' << dp[i] << endl;
    cout << dp[x];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}