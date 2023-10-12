#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define dub long double
#define ins insert

template<class T1> bool maximize(T1 &a, T1 b) {if(b > a) {a = b; return 1;} return false;}
template<class T1> bool minimize(T1 &a, T1 b) {if(b < a) {a = b; return 1;} return false;}
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

typedef pair<int, int> pi;
typedef vector<int> vi;

struct Edge {
    int u, v, w;
    Edge() = default;
    Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
    bool operator < (const Edge &e) {
        return w < e.w;
    }
}; vector<Edge> e;
vi p;
int find(int k) {
    if(k == p[k]) return p[k];
    return p[k] = find(p[k]);
}
void connect(int u, int v) {
    u = find(u); v = find(v);
    p[u] = v;
}
int n, m, u, v, year, tplt = 0;
inline void solve() {
    cin >> n >> m;
    tplt = n;
    p.resize(n + 10);
    for(int i = 1; i <= n; i++) p[i] = i;
    while(m--) {
        cin >> u >> v >> year;
        e.pb(Edge(u, v, year));
        u = find(u); v = find(v);
        if(u != v) {
            tplt--;
            connect(u, v);
        }
    }
    if(tplt != 1) {
        cout << -1;
        return;
    }
    for(int i = 1; i <= n; i++) p[i] = i;
    sort(all(e));
    tplt = n;
    for(int i = e.size() - 1; i >= 0; i--) {
        u = find(e[i].u); v = find(e[i].v);
        cout << e[i].w << endl;
        if(u != v) {
            connect(e[i].u, e[i].v);
            tplt--;
        }
        if(tplt == 1) {
            cout << e[i].w;
            return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("FPATH.INP", "r", stdin);
    freopen("FPATH.OUT", "w", stdout);

    solve();
}
/*
TEST CASE 1:
6 8
1 2 7
1 3 5
1 4 2
2 3 4
3 5 6
3 6 10
4 5 9
5 6 1

TEST CASE 2:
,,__,,
*/
