 /*
Good luck for those who are trying your best
May the most glorious victory come
File name: GuardMarks.cpp
Code by : acident / lckintrovert
Created since : 08/09/2023 ~~ 10:41:52
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
int const INF       =       1e9 + 10;
 
//Problem link : http://www.usaco.org/index.php?page=viewproblem2&cpid=494
int cows, height;
int he, we, str;
vector<pii> a;
int dp[(1 << 20) + 10] = {}, h[(1 << 20) + 10] = {};
void solve() {
    cin >> cows >> height;
    for(int i = 1; i <= cows; i++) {
        cin >> he >> we >> str;
        a.pb(mp(str, mp(we, he)));
    }
    int ans = -1;
    dp[0] = INF;
    for(int mask = 1; mask < (1 << cows); mask++) {
        dp[mask] = -1;
        for(int i = 0; i < cows; i++) {
            if(mask & (1 << i)) {
                h[mask] += a[i].se.se;
                if(dp[mask ^ (1 << i)] >= a[i].se.fi) 
                    maximize(dp[mask], min(dp[mask ^ (1 << i)] - a[i].se.fi, a[i].fi));
            }
        }
        if(h[mask] >= height) ans = max(ans, dp[mask]);
    }
    if(ans == -1) cout << "Mark is too tall";
    else cout << ans;

}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/