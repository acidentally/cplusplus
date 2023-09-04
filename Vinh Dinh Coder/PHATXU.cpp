/*
Good luck for those who are trying your best
May the most glorious victory come
File name: PHATXU.cpp
Code by : acident / lckintrovert
Created since : 02/09/2023 ~~ 23:13:21
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
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, u, v, q;
map<int, int> m;
void solve() {
    cin >> n >> q;
    while(q--) {
        cin >> u >> v;
        if(u <= v) {
            m[u]++;
            m[v + 1]--;
        }
        else {
            m[1]++; m[v + 1]--;
            m[u]++; m[n + 1]--;
        }
    }
    int ans = 0, c = 0, d = 0;
    vector<pi> save;
    for(auto s : m) {
        d += s.se;
        save.pb(mp(s.fi, d));
        ans = max(ans, d);
    }
    for(int i = 0; i < save.size() - 1; i++) {
        if(save[i].se == ans) c += save[i + 1].fi - save[i].fi;
    }
    cout << ans << ' ' << c;
}
main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();

    
}

/*A place to scribble thoughts

*/