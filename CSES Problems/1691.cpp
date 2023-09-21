/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1691.cpp
Code by : acident / lckintrovert
Created since : 21/09/2023 ~~ 16:22:53
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                  long long
#define uint                 unsigned long long
#define dub                  double
#define fi                   first
#define se                   second
#define endl                 '\n'
#define pb                   push_back
#define pf                   push_front
#define eb                   emplace_back
#define ins                  insert
#define mp                   make_pair
#define all(a)               a.begin(), a.end()
#define YES                  cout << "YES\n"
#define NO                   cout << "NO\n"
#define coutdub(x)           cout << fixed << setprecision(x)
#define cerrdub(x)           cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
const int mod       =        1e9 + 7;
const int maxn      =        1e5 + 10;
const int INF       =        1e18;

int n, m, u, v;
vector<pi> e, a[maxn] = {};
vi ans;
bool vis[maxn << 1 + 10] = {};
void DFS(int k) {
    while(!a[k].empty()) {
        if(!vis[a[k].back().se]) {
            vis[a[k].back().se] = 1;
            int temp = a[k].back().fi;
            a[k].pop_back();
            DFS(temp);
        }
        else a[k].pop_back();
    }
    ans.pb(k);
}
inline void solve() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        a[u].pb(mp(v, i));
        a[v].pb(mp(u, i));
    }
    for(int i = 1; i <= n; i++) {
        if(a[i].size() & 1) {
            cout << "IMPOSSIBLE";
            exit(0);
        }
    }
    DFS(1);
    if(ans.size() != m + 1) {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    for(auto s : ans) cout << s << ' ';
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/