#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define dub long double
#define ins insert
#define endl '\n'
#define mp make_pair

template<class T1> bool maximize(T1 &a, T1 b) {if(b > a) {a = b; return 1;} return false;}
template<class T1> bool minimize(T1 &a, T1 b) {if(b < a) {a = b; return 1;} return false;}
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;

typedef pair<int, int> pi;
typedef vector<int> vi;

struct Edge {
    int u, v, col;
    Edge() = default;
    Edge(int u_, int v_, int w_) : u(u_), v(v_), col(w_) {}
};

bool check(Edge e1, Edge e2) {
    if(e1.u > e2.u) swap(e1, e2);
    else if(e1.u == e2.u && e1.v < e2.v) swap(e1, e2);
    return ( (e1.u <= e2.u && e2.v <= e1.v) || (e2.u >= e1.v) );
}
int n;
int a[2010][2010] = {};
int in[2010] = {};
vi adjList[maxn] = {};
bool del[2010] = {};
void sub1() {
    vector<Edge> e;
    memset(in, 0, sizeof(in));
    memset(a, 0, sizeof(a));
    memset(del, 0, sizeof(del));
    for(int i = 1; i <= n; i++) adjList[i].clear();

    int u, v, col;
    char x;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        in[i] = 2;
        a[i][i % n + 1] = a[i % n + 1][i] = x - '0'; //map can be used
        adjList[i].pb(i % n + 1);
        adjList[i % n + 1].pb(i);
    }
    for(int i = 1; i <= n - 3; i++) {
        cin >> u >> v >> col;
        a[u][v] = a[v][u] = col; //can be logn
        adjList[u].pb(v);
        adjList[v].pb(u);
        if(u > v) swap(u, v);
        e.pb(Edge(u, v, col));
    }
    for(int i = 0; i < e.size(); i++) { //can be optimized
        for(int j = i - 1; j >= 0; j--) {
            if(!check(e[i], e[j])) {cout << -1 << endl; return;}
        }
        in[e[i].u]++; in[e[i].v]++;
    }
    priority_queue<pi, vector<pi>, greater<pi> > q;
    for(int i = 1; i <= n; i++) q.push(mp(in[i], i));
    while(!q.empty()) {
        int u = q.top().se, du = q.top().fi;
        q.pop();
        if(du != in[u] || del[u]) continue;
        del[u] = true;
        //cout << u << endl;
        bool cnt = 0; int ne[2] = {};
        for(auto s : adjList[u]) { //?!?
            if(cnt == 1) break;
            if(del[s]) continue;
            ne[cnt++] = s;
        }
        in[ne[0]]--; in[ne[1]]--;
        //cout << u << ' ' << ne[0] << ' ' << ne[1] << endl;
        if(a[u][ne[0]] + a[u][ne[1]] + a[ne[0]][ne[1]] != 6) { //same here
            cout << 0 << endl;
            return;
        }
        if(in[ne[0]] == 2) q.push(mp(2, ne[0]));
        if(in[ne[1]] == 2) q.push(mp(2, ne[1]));
    }
    cout << 1 << endl;
}
void sub2() {

}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("TAMGIAC.INP", "r", stdin);
    freopen("TAMGIAC.OUT", "w", stdout);

    //cout << check(Edge(1, 5, 2), Edge(6, 7, 3));

    int t; cin >> t;
    while(t--) {
        cin >> n;
        sub1(); //toi bi ngu
    }

}
