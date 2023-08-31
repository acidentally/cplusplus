/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1637.cpp
Code by : acident / lckintrovert
Created since : 23/08/2023 ~~ 22:06:53
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
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e6 + 10;
int const INF       =       1e18;
 
int n;
int dp[maxn] = {};
vi compute(int k) {
    vi a;
    while(k) {
        a.pb(k % 10);
        k /= 10;
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    return a;
}
void solve() {
    cin >> n;
    for(int i = 0; i <= n; i++) dp[i] = maxn;
    dp[n] = 0;
    for(int i = n; i >= 1; i--) {
        vi a = compute(i);
        for(auto s : a) if(i - s >= 0) dp[i - s] = min(dp[i - s], dp[i] + 1);
    }
    // for(int i = 0; i <= n; i++) {
    //     cerr << dp[i] << endl;
    // }
    cout << dp[0];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/