/*
Good luck for those who are trying your best
May the most glorious victory come

File name: usaco_dp_phidias.cpp
Code by : acident / lckintrovert
Created since : 2023-08-03 ~~ 20:03:04
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
int const mod          =    1e9 + 7;
int const maxn         =    1000;
int const INF          =    LLONG_MAX;

int W, H, n;
pi a[maxn] = {};
int dp[maxn][maxn] = {};
void solve() {
    cin >> W >> H;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for(int i = 1; i <= W; i++) {
        for(int j = 1; j <= H; j++) {
            for(int bri = 0; bri < n; bri++)  {
                
            }
        }
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}