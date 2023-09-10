/*
Good luck for those who are trying your best
May the most glorious victory come
File name: MoovieMooving.cpp
Code by : acident / lckintrovert
Created since : 10/09/2023 ~~ 08:22:12
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

typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       (1 << 20) + 10;
int const INF       =       1e9;

int n, l, c, x;
int d[30] = {}, ans = 50, place;
vi a[30] = {};
int dp[maxn] = {};
void solve() {
    cin >> n >> l;
    for(int i = 0; i < n; i++) {
        cin >> d[i] >> c;
        while(c--) {
            cin >> x;
            a[i].pb(x);
        }
    }
    dp[0] = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
        for(int movie = 0; movie < n; movie++) {
            if(mask & (1 << movie)) {
                x = dp[mask ^ (1 << movie)];
                maximize(dp[mask], x);
                place = upper_bound(all(a[movie]), x) - a[movie].begin() - 1;
                if(place < 0 || a[movie][place] > x) continue;
                else {
                    maximize(dp[mask], a[movie][place] + d[movie]);
                }
            }
        }
        if(dp[mask] >= l) minimize(ans,(int)__builtin_popcount(mask));
    }
    if(ans == 50) cout << -1;
    else cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("movie.in", "r", stdin);
    // freopen("movie.out", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/