#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dub long double
#define fi first
#define se second
#define pb push_back
#define ins insert
#define endl '\n'
#define mp make_pair

template<class T1> bool minimize(T1 &a, T1 b) {if(b < a){a = b; return true;} return false;}
template<class T1> bool maximize(T1 &a, T1 b) {if(b > a){a = b; return true;} return false;}

typedef vector<int> vi;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int INF = 1e15;
const int maxn = 1e3 + 10;

struct Edge {
    int u, v, w;
    Edge() = default;
    Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
}; vector<Edge> e;

int n, m, c, cur = 0;
int d1[maxn] = {};
int exist[maxn][maxn] = {};

void Dijkstra(int s1, int s2) {
    int u, v, du, dv;
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    d1[s1] = 0; d1[s2] = 0;
    pq.push(mp(0, s1)); pq.push(mp(0, s2));
    while(!pq.empty()) {
        u = pq.top().se; du = pq.top().fi;
        pq.pop();
        if(du > d1[u]) continue;
        for(int i = 1; i <= n; i++) {
            if(exist[u][i] == 0) continue;
            v = i; dv = exist[u][i];
            if(du + dv < d1[v]) {
                d1[v] = du + dv;
                pq.push(mp(d1[v], v));
            }
        }
    }
}
int u, v;
void solve(void) {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> c;
        if(!exist[u][v]) exist[u][v] = exist[v][u] = c;
        else {minimize(exist[u][v], c); minimize(exist[v][u], c);}
        e.pb(Edge(u, v, c));
    }
    int ans = INF, res = 0, holder;
    bool check = true;
    for(int i = 0, holder; i < e.size(); i++) {
        u = e[i].u; v = e[i].v;
        holder = exist[u][v];
        exist[u][v] = exist[v][u] = 0;

        for(int j = 1; j <= n; j++) {d1[j] = INF;}
        Dijkstra(u, v);

        exist[u][v] = exist[v][u] = holder;
        check = true; cur = 0;
        for(int j = 1; j <= n && check; j++) {
            if(j == u || j == v) continue;
            if(d1[j] == INF) check = false;
            maximize(cur, d1[j]);
        }
        if(!check) continue;
        else if(minimize(ans, cur)) {
            res = i + 1;
        }
    }
    cout << res << ' ' << ans;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("TRIENLAM.INP", "r", stdin);
    freopen("TRIENLAM.OUT", "w", stdout);
    solve();
}
