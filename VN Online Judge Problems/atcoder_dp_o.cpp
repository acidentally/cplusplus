/*
Good luck for those who are trying your best
May the most glorious victory come
File name: atcoder_dp_o.cpp
Code by : acident / lckintrovert
Created since : 11/09/2023 ~~ 08:28:06
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)
 
//#define _USE_MATH_DEFINES // If meth .__.
 
template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
template<class T1> T1 abs(T1 a) {return max(a, -a);}
 
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       50;
int const INF       =       1e18;
 
int n;
int dp[(1 << 21) + 10] = {};
bool a[25][25] = {};
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