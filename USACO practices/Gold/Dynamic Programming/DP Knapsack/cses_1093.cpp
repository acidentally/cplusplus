/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1093.cpp
Code by : acident / lckintrovert
Created since : 23/08/2023 ~~ 14:19:18
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
int const maxn      =       2e5 + 10;
int const INF       =       1e18;
 
int n;
int dp[maxn] = {};
void solve() {
    cin >> n;
    if(n * (n + 1) % 4) {
        cout << 0;
        return;
    }
    int mid = (n * (n + 1)) >> 2;
    // cout << mid << endl;
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = mid; j >= 1; j--) {
            if(j - i < 0) break;
            (dp[j] += dp[j - i]) %= mod;
        }
    }
    if(dp[mid] & 1) {
        cout << ((dp[mid] + mod) >> 1);
    } else cout << (dp[mid] >> 1);
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/




