
/*
Good luck for those who are trying your best
May the most glorious victory come
File name: Matching.cpp
Code by : acident / lckintrovert
Created since : 03/09/2023 ~~ 22:10:13
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
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       3e6 + 10;
int const INF       =       1e18;
 
int n;
int a[30][30] = {};
int dp[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }  
    dp[0] = 1;
    for(int womask = 0; womask < (1 << n) - 1; womask++) {
        int man = __builtin_popcount(womask);
        for(int woman = 0; woman < n; woman++) {
            if(a[man][woman] && !(womask & (1 << woman))) {
                (dp[womask | (1 << woman)] += dp[womask]) %= mod;
            }
        }
    }
    cout << dp[(1 << n) - 1];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/