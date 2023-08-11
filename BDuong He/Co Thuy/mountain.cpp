/*
Good luck for those who are trying your best
May the most glorious victory come
File name: mountain.cpp
Code by : acident / lckintrovert
Created since : 09/08/2023 ~~ 08:31:34
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
 
int n, u, v;
pi a[maxn] = {};
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> u >> v;
        a[i] = mp(u - v, u + v);
    }
    sort(a + 1, a + 1 + n);
    int l = -1, r = -1, ans = n;
    for(int i = 1; i <= n; i++) {
        if(a[i].fi >= r) {
            l = a[i].fi;
            r = a[i].se;
            continue;
        }
        if(a[i].fi == l) {
            ans--;
            r = max(a[i].se, r);
        }
        else if(a[i].se <= r) {
            ans--;
        }
        else {
            l = a[i].fi;
            r = a[i].se;
        }
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    // freopen("mountain.INP", "r", stdin);
    // freopen("mountain.OUT", "w", stdout);
    solve();
}