/*
Good luck for those who are trying your best
May the most glorious victory come
File name: pp.cpp
Code by : acident / lckintrovert
Created since : 04/09/2023 ~~ 14:22:44
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
int const maxn      =       1e3 + 10;
int const INF       =       1e10;
 
int n, m, u, v, w, x, du, dv;
int sta, en, af, places;
int TwoDimen[maxn][maxn] = {}, d[maxn] = {};
bool checkOccu[maxn][maxn] = {};
vector<pi> AdjList[maxn];
pi Occu[maxn][maxn] = {};
vi g;
pi temp;

void Dijkstra() {
    int l, r;
    priority_queue<pi, vector<pi>, greater<pi> > q;
    q.push(mp(af, sta));
    while(!q.empty()) {
        du = q.top().fi, u = q.top().se;
        q.pop();
        if(du != d[u]) continue;
        for(auto adj : AdjList[u]) {
            dv = adj.fi; v = adj.se;
            if(!checkOccu[u][v]) {
                if(du + dv < d[v]) {
                    d[v] = du + dv;
                    q.push(mp(d[v], v));
                } 
                continue;
            }
            temp = Occu[u][v];
            l = temp.fi, r = temp.se;
            int ED = du + dv;
            if(du + dv < l || r <= du) {}
            else ED = r + dv;
            if(ED < d[v]) {
                d[v] = ED;
                q.push({d[v], v});
            }
            
        }
    }
}
void solve() {
    cin >> n >> m;
    cin >> sta >> en >> af >> places;
    for(int i = 1; i <= places; i++) {
        cin >> x;
        g.pb(x);
    }
    while(m--) {
        cin >> u >> v >> w;
        TwoDimen[u][v] = TwoDimen[v][u] = w;
        AdjList[u].pb(mp(w, v));
        AdjList[v].pb(mp(w, u));
    }
    for(int i = 0, cur = 0; i < g.size() - 1; i++) {
        u = g[i]; v = g[i + 1];
        Occu[v][u] = Occu[u][v] = mp(cur, cur + TwoDimen[u][v]);
        checkOccu[u][v] = checkOccu[v][u] = 1;
        cur += TwoDimen[u][v];
    }
    for(int i = 1; i <= n; i++) {
        d[i] = INF;
    }
    d[sta] = af;
    Dijkstra();
    cout << d[en] - af << endl;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // freopen("pp.inp", "r", stdin);
    // freopen("pp.out", "w", stdout);
    solve();
}

/*A place to scribble thoughts

*/