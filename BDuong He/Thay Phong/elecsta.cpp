/*
Good luck for those who are trying your best
May the most glorious victory come
File name: elecsta.cpp
Code by : acident / lckintrovert
Created since : 15/08/2023 ~~ 14:22:13
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
int const maxn      =       4e5 + 10;
int const INF       =       1e18;
 
struct DSU {
    vi p;
    DSU() : p(maxn) {}
    void createDSU(int l) {
        for(int i = 1; i <= l; i++) p[i] = i;
    }
    int find(int v) {
        if(v == p[v]) return v;
        return p[v] = find(p[v]);
    }
    void make(int i) {
        p[i] = i;
    }
    void connect(int u, int v) {
        u = find(u); v = find(v);
        p[u] = v;
    }
}g1 ;

int n, m, u, v, w, q;
vector<pii> a;
void solve() {
    cin >> n >> m;
    while(m--) {
        cin >> u >> v >> w;
        a.pb(mp(w, mp(u, v)));
    }
    sort(all(a));
    cin >> q;
    while(q--) {
        cin >> u >> v;
        g1.createDSU(n);
        g1.connect(u, v);
        int ans = 0;
        for(auto s : a) {
            if(g1.find(s.se.fi) == g1.find(s.se.se)) continue;
            ans += s.fi;
            g1.connect(s.se.fi, s.se.se);
        }
        cout << ans << endl;
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}