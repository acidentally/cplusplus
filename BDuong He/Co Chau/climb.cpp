/*
Good luck for those who are trying your best
May the most glorious victory come
File name: climb.cpp
Code by : acident / lckintrovert
Created since : 18/08/2023 ~~ 08:00:27
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
int const maxn      =       3e4 + 10;
int const INF       =       1e18;
 
int n;
int up[maxn] = {}, down[maxn] = {};
pi b[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> up[i] >> down[i];
        b[i] = mp(up[i], i);
    }
    sort(b + 1, b + n + 1);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += max(up[b[i].se], down[b[i - 1].se]);
    }
    // cerr << b[n].se;
    cout << ans + b[n].se;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("climb.INP", "r", stdin);
    // freopen("climb.OUT", "w", stdout);
    solve();
}