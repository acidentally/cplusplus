/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1869E.cpp
Code by : acident / lckintrovert
Created since : 11/09/2023 ~~ 20:36:35
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
int const maxn      =       1e5 + 10 //VERY BIG NUMBER BTW;
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
} g1;
int n, m, x, q, u, v;

void solve() {
    cin >> n >> m >> q;
    g1.createDSU(n + 10);
    vi a[m + 10] = {};
    int mapp[n + 10] = {};
    for(int i = 1; i <= n; i++) {
        cin >> x;
        a[x].pb(i);
        mapp[i] = x;
    }
    for(int i = 1; i <= q; i++) {
        cin >> u >> v;
        g1.connect(u, v);
        
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--) solve();
}

/*A place to scribble thoughts

*/