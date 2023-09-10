/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1316E.cpp
Code by : acident / lckintrovert
Created since : 09/09/2023 ~~ 09:52:39
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
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define ins                 insert
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)
 
template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, p, k, x;
int s[maxn][10] = {};
int dp[maxn][200] = {};
vector<pi> a = {};
void solve() {
    cin >> n >> p >> k;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        a.pb(mp(~x, i));
    }
    a.pb(mp(-INF, -INF));
    sort(all(a));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < p; j++) {
            cin >> s[i][j];
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i < a.size(); i++) {
 
        int idx = a[i].se;
        int val = ~a[i].fi;
        
        for(int mask = 0; mask < (1 << p); mask++) {
 
            for(int j = 0; j < p; j++) {
                if(mask & (1 << j)) {
                    maximize(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + s[idx][j]);
                }
            }
 
            int aud = i - __builtin_popcount(mask);
            if(aud <= 0) {}
            else if(aud > k) maximize(dp[i][mask], dp[i - 1][mask]);
            else maximize(dp[i][mask], dp[i - 1][mask] + val);
        }
    }
    cout << dp[n][(1 << p) - 1];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}
/*A place to scribble thoughts
 
*/